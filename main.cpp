#include <iostream>
#include "pqueue.h"
using namespace std;

int main(){
    pqueue pq(8, false);

    pq.insert(0,5);
    pq.insert(1,1);
    pq.insert(2,10);
    pq.insert(3,7);
    pq.insert(4,9);
    pq.insert(7, -1);
    pq.insert(6, 3);
    pq.insert(5, 200);

    int id; double priority;

    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }

    pq.insert(0,5);
    pq.insert(1,1);
    pq.insert(2,10);
    pq.insert(3,7);
    pq.insert(4,9);
    pq.insert(7, -1);
    pq.insert(6, 3);
    pq.insert(5, 200);

    for (int i = 0; i < pq.heap.size(); i++){
        cout << pq.heap.at(i) << " ";
    }
    cout << endl << endl;


    // for (int i = 0; i < 8; i++){
    //     pq.remove_by_id(i);
    //     for (int i = 0; i < pq.heap.size(); i++){
    //         cout << pq.heap.at(i) << " ";
    //     }
    //     cout << endl;
    // }


    pq.insert(0,5);
    pq.insert(1,1);
    pq.insert(2,10);
    pq.insert(3,7);
    pq.insert(4,9);
    pq.insert(7, -1);
    pq.insert(6, 3);
    pq.insert(5, 200);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;


    pq.change_priority(0, 15);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    pq.change_priority(0, 0);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    pq.change_priority(5, 300);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    pq.change_priority(1, 8);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    pq.change_priority(1, -1);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    pq.delete_top(id, priority);
    pq.delete_top(id, priority);
    pq.delete_top(id, priority);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    // pq.change_priority(5, 0);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl << endl;

    //    pq.change_priority(5, 1000);

    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    cout << endl << endl;

    pq.peek_top(id, priority);

    cout << id << " " << priority << endl;

    pq.delete_top(id, priority);

      pq.peek_top(id, priority);

    cout << id << " " << priority << endl;


    // for (int i = 0; i < pq.idMap.size(); i++){
    //     if (pq.idMap.at(i) != -1){
    //         //cout << pq.idMap.at(i) << " ";
    //         cout << "id: " << i << " value: " << pq.heap.at(pq.idMap.at(i)) << " ";
    //     }
    //     else{
    //         cout << "i: "  << i << " ";
    //     }
    // }
    // cout << endl;
    // cout << endl;
    // int a;
    // double b;
    // pq.delete_top(a, b);
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl;
    // pq.delete_top(a, b);
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl;
    // pq.delete_top(a, b);
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl;
    // pq.delete_top(a, b);
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl;
    // pq.delete_top(a, b);
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }
    // cout << endl;

    // cout << endl;
    // pq.change_priority(4, 100);
    
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }

    // // cout << endl;
    // pq.change_priority(2, 5);
    
    // for (int i = 0; i < pq.heap.size(); i++){
    //     cout << pq.heap.at(i) << " ";
    // }

    return 0;
}

struct Node{
  Node(Node* firstChild, Node* sibling){
    this->firstChild = firstChild;
    this->sibling = sibling;
  }
  Node* firstChild;
  Node* sibling;
};

bool validBitTree(vector<int> bits){
  //bits.size % 2 == 0
  //# of 1's == size / 2 && # of 0's == size / 2
  //first bit == 1, last bit == 0
}

//Note: 01 sequence implies sibling...

Node* bitsToTree(vector<int> bits){
  if (!validBitTree)
    return nullptr;

  vector<Node*> levelNode(bits.size() + 1, nullptr);
  Node* root = new Node(nullptr, nullptr);
  levelNode.push_back(root);
  int level = 0;

  bool zeroPrev = false;
  for (int i = 0; i < bits.size(); i++){
    if (bits.at(i) == 0){ //Going up tree, do not add node.
      zeroPrev = true;
      level--;
    }
    else{
      Node* node = new Node(nullptr, nullptr);
      level++;

      if (zeroPrev){ //This node is a sibling
        levelNode.at(level)->sibling = node;
        levelNode.at(level) = node;
      }
      else{ //This node is a child
        levelNode.at(level - 1)->firstChild = node;
        levelNode.at(level) = node;
      }
      
      zeroPrev = false;
    }
  }

  return root;
}