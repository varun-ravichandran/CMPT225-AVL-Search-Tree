//
//  main.cpp
//  Assignment 3
//
//  Created by Varun Ravichandran on 2020-11-28.
//

#include <iostream>
#include <time.h>
#include "dsexceptions.h"
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

void nop(int nop)   // nop - number of operations
{
    BinarySearchTree<int> BST;
    AvlTree<int> AVL;
    
    clock_t start_time, end_time;
    start_time = clock();
    for(int i=0; i<nop; i++)
    {
        BST.insert(i+700);
    }
    for(int i=0; i<nop/2; i++)
    {
        BST.remove(i+750);
    }
    for(int i=0; i<nop; i++)
    {
        BST.insert(i+90);
    }
    for(int i=0; i<nop; i++)
    {
        BST.contains(i+90);
    }
    for(int i=0; i<nop/2; i++)
    {
        BST.remove(i+500);
    }
    end_time = clock();
    double time_takenBST = elapsed_time(start_time, end_time);
    
    // Time and operations done for AVL tree
    start_time = clock();
    for(int i=0; i<nop; i++)
    {
        AVL.insert(i+700);
    }
    for(int i=0; i<nop/2; i++)
    {
        AVL.remove(i+750);
    }
    for(int i=0; i<nop; i++)
    {
        AVL.insert(i+90);
    }
    for(int i=0; i<nop; i++)
    {
        AVL.contains(i+90);
    }
    for(int i=0; i<nop/2; i++)
    {
        AVL.remove(i+500);
    }
    end_time = clock();
    double time_takenAVL = elapsed_time(start_time, end_time);
    
   
    
    cout << "\n\nBST tree test" << endl << endl;
    
    cout << "Height of the tree: " << BST.height() << endl ;
    double size_BST = BST.size();
    cout << "Size of the tree: "<<size_BST<<endl;
    cout << "Sum of the depth node: "<<BST.IPL()<< endl;
    double BST_avgNode = BST.IPL()/size_BST/2;
    cout << "Average node depth: "<<BST_avgNode<<endl;
    
    cout << "Time units: milliseconds"<< endl;
    cout << "Average time taken for BST tree: "<<time_takenBST/nop<<" ms"<<endl;
    
    cout << "\n\nAVL tree test" << endl << endl;

    cout << "Height of the tree: " <<AVL.height() << endl ;
    double size_AVL = AVL.size();
    cout << "Size of the tree: "<<size_AVL<<endl;
    cout << "Sum of the depth node: "<<AVL.IPL()<<endl;
    double AVL_avgNode = AVL.IPL()/size_AVL/2;
    cout << "Average node depth: "<<AVL_avgNode<<endl;
    cout << "Average time taken for AVL tree: "<<time_takenAVL/nop<<" ms"<<endl;
}

int main()
{
    BinarySearchTree<int> BST;
    AvlTree<int> AVL;
    for(int i=1000; i<=10000;)
    {
        nop(i); // nop - number of operations
        i=i+1000;
    }
    
    return 0;
}
