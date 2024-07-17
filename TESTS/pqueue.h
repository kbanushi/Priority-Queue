// #include "pq.h"
#include <stdlib.h>
#include <cstdlib>
#include <vector>
using namespace std;

#ifndef PQUEUE
#define PQUEUE

/**
* General description:  priority queue class which stores pairs
*   <id, priority>.  Top of queue is determined by priority
*   (min or max depending on configuration).
*
*   There can be only one (or zero) entry for a particular id.
*
*   Capacity is fixed on creation.
*
*   IDs are integers in the range [0..N-1] where N is the capacity
*   of the priority queue set on creation.  Any values outside this
*   range are not valid IDs.
**/

class pqueue {
    private:  // maybe put your data members (and types if desired) here
        
        vector<double> heap;
        vector<int> idMap;
        vector<int> mapToIds;
        bool min_heap;
        int cap;

        bool compare(double left, double right){
            return (min_heap) ? left < right : left > right;
        }

        bool isValid(int pos){
            return (pos >= 0 && pos < cap);
        }



        int findMinChildIndex(vector<double>& heap, int index){
            int left = index * 2 + 1, right = index * 2 + 2;
            
            if (left > heap.size() - 1)
                return -1;
            if (left == heap.size() -1 || heap.at(left) < heap.at(right))
                return left;
            return right;
        }

        int percUp(int pos){
            double value = heap.at(pos);

            int end = pos;
            int parent = end / 2;
            while (end > 0 && compare(value, heap.at(parent))){ //The end gets updated and never changes again
                idMap.at(mapToIds.at(parent)) = end; //parent just moved down to end
                mapToIds.at(end) = mapToIds.at(parent); //mapToIds at end is now updated with the parent one
                heap.at(end) = heap.at(parent); //send parent down

                end = parent;
                parent = end / 2;
            }
            heap.at(end) = value;
            return end;
        }

        int percDown(int pos){
            if (heap.size() == 0)
                return -1;

            double value = heap.at(pos);
            int child = findMinChildIndex(heap, pos);
            while (child > -1 && compare(heap.at(child), value)){
                idMap.at(mapToIds.at(child)) = pos;
                mapToIds.at(pos) = mapToIds.at(child);       
                heap.at(pos) = heap.at(child);

                pos = child;
                child = findMinChildIndex(heap, pos);
            }
            heap.at(pos) = value;

            return pos;
        }
    
        

    public:
 

        /**
         * TODO
         * CONSTRUCTOR
         * Parameters: capacity - self-explanatory
         *             min_heap - if true (really non-zero), then it is a min-heap
         *                        if false, then a max-heap
         *
         *
         */
        pqueue(int capacity, bool min_heap=true){
            idMap = vector<int>(capacity, -1);
            mapToIds = vector<int>(capacity, -1);

            this->min_heap = min_heap;
            this->cap = capacity;
        }

        /**
         * TODO
         * Destructor
         * Desc: deallocates all memory associated with passed priority
         *       queue.
         * Runtime: Theta(Capacity of Queue)
         */
        ~pqueue() {
        }



        /**
         * TODO
         * Function: insert
         * Parameters: id of entry to insert
         *             priority of entry to insert
         * Returns: true on success; false on failure.
         *          fails if id is out of range or
         *            there is already an entry for id
         *          succeeds otherwise.
         *
         * Desc: self-explanatory
         *
         * Runtime:  O(log n)
         *
         */
        bool insert(int id, double priority){
            if (!isValid(id) || idMap.at(id) != -1)
                return false;
            
            heap.push_back(priority);
            int heapIndex = percUp(heap.size() - 1);

            idMap.at(id) = heapIndex;
            mapToIds.at(heapIndex) = id;

            return true;
        }

        /**
         * TODO
         * Function: change_priority
         * Parameters: element id
         *             new_priority
         * Returns: true on success; false on failure
         * Desc: If there is an entry for the given id, its associated
         *       priority is changed to new_priority and the data
         *       structure is modified accordingly.
         *       Otherwise, it is a failure (id not in pq or out of range)
         * Runtime:  O(log n)
         *
         */
        bool change_priority(int id, double new_priority){
            if (!isValid(id) || idMap.at(id) == -1)
                return false;
            
            int heapIndex = idMap.at(id), index;
            if (new_priority > heap.at(heapIndex)){ //perc down
                heap.at(heapIndex) = new_priority;

                index = percDown(heapIndex);
                idMap.at(id) = index;
                mapToIds.at(index) = id;
            }
            else if (new_priority < heap.at(heapIndex)){
                heap.at(heapIndex) = new_priority;

                index = percUp(heapIndex);
                idMap.at(id) = index;
                mapToIds.at(index) = id;
            }

            return true;
        }

        /**
         * TODO
         * Function: remove_by_id
         * Parameters: element id
         * Returns: true on success; false on failure
         * Desc: if there is an entry associated with the given id, it is
         *       removed from the priority queue.
         *       Otherwise the data structure is unchanged and 0 is returned.
         * Runtime:  O(log n)
         *
         */
        bool remove_by_id(int id){
            if (!isValid(id) || idMap.at(id) == -1)
                return false;

            //if (

            int i = mapToIds.at(heap.size() - 1), heapIndex = idMap.at(id);
            
            mapToIds.at(heap.size() - 1) = -1;
            idMap.at(id) = -1;

            double current = heap.at(heapIndex), last = heap.at(heap.size() - 1); 
            
            heap.at(heapIndex) = heap.at(heap.size() - 1); //replace with last element
            heap.pop_back();

            if (!heap.size()){
                idMap = vector<int>(cap, -1);
                mapToIds = vector<int>(cap, -1);
                return true;
            }

            int index;
            if (current < last){
                index = percDown(heapIndex);
                idMap.at(i) = index;
                mapToIds.at(index) = i;
            }
            else if (current > last){
                index = percUp(heapIndex);
                idMap.at(i) = index;
                mapToIds.at(index) = i;
            }

            return true;
        }

                /**
         * TODO
         * Function: delete_top
         * Parameters: reference int id and ref priority ("out" parameters)
         * Returns: true on success; false on failure (empty priority queue)
         * Desc: if queue is non-empty the "top" element is deleted and
         *       its id and priority are stored in *id and *priority;
         *       The "top" element will be either min or max (wrt priority)
         *       depending on how the priority queue was configured.
         *
         *       If queue is empty, 0 is returned.
         *
         * Runtime:  O(log n)
         *
         *
         */
        bool delete_top(int &id, double &priority){
            if (!heap.size())
                return false;

            id = mapToIds.at(0);
            priority = heap.at(0);

            int i = mapToIds.at(heap.size() - 1);
            idMap.at(id) = -1;
            mapToIds.at(heap.size() - 1) = -1;
            heap.at(0) = heap.at(heap.size() - 1);
            heap.pop_back();

            if (heap.size()){
                int heapIndex = percDown(0);
                idMap.at(i) = heapIndex;
                mapToIds.at(heapIndex) = i;
            }
            else{
                idMap = vector<int>(cap, -1);
                mapToIds = vector<int>(cap, -1);
            }
            
            return true;
        }



        /**
         * TODO
         * Function: get_priority
         * Parameters: elment id
         *             reference double priority ("out" param)
         * Returns: true on success; false on failure
         * Desc: if there is an entry for given id, priority is assigned
         *       the associated priority and true is returned.
         *       Otherwise false is returned and priority has no meaning.
         * Runtime:  O(1)
         *
         */
        bool get_priority(int id, double &priority){
            if (!isValid(id) || idMap.at(id) == -1)
                return false;

            priority = heap.at(idMap.at(id));
            return true;
        }



        /**
         * TODO
         * Function: peek_top
         * Parameters: reference int id and ref priority ("out" parameters)
         * Returns: true on success; false on failure (empty priority queue)
         * Desc: if queue is non-empty information about the "top"
         *       element (id and priority) is stored in *id and *priority;
         *       The "top" element will be either min or max (wrt priority)
         *       depending on how the priority queue was configured.
         *
         *       The priority queue itself is unchanged (contrast with
         *       delete_top).!
         *
         *       If queue is empty, 0 is returned.
         *
         * Runtime:  O(1)
         *
         */
        bool peek_top(int &id, double &priority){
            if (!heap.size())
                return false;
            
            priority = heap.at(0);
            id = mapToIds.at(0);

            return true;
        }

        /**
         * TODO
         * Function:  capacity
         * Returns: capacity of priority queue (as set on creation)
         * Desc: see returns
         *
         * Runtime:   O(1)
         *
         */
        int capacity() {
            return cap;
        }

        /**
         * TODO
         * Function: size
         * Returns: number of elements currently in queue
         * Desc: see above
         *
         * Runtime:  O(1)
         */
        int size() {
            return heap.size();
        }
};

#endif