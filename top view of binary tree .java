import java.io.*;
import java.util.*;
class code 
{
    static class Node
    {
        int data;
        Node left;
        Node right;
        
        Node(int num)
        {
            data = num;
            left = right = null;
        }
    };
    // class definition to handle pairs
    static class pair
    {
        int nodeData;
        int height;
        
        pair(int key,int num)
        {
            nodeData = key;
            height = num;
        }
    }
    
    /* the function performs inorder traversal and stores top view
    of the binary tree. 
    for every node encountered during the traversal we have it's : 
    w -> horizontal depth(width)
    h -> vertical depth(height)
    */
    static void inorder(Node root,int w,int h, TreeMap <Integer,pair> Map)
    { 
        if(root == null) 
        return; 
        
        inorder(root.left,w-1,h+1,Map);
        
        /* check if a particular horizontal level has been visited or not */
        if(!Map.containsKey(w))
            Map.put(w,new pair(root.data,h)); 
        
        /* if particular horizontal level has been visited 
        then check if height of current node is less than
        the previous node met at same horizontal level, if this 
        is true then the current node should replace previous node
        in top view of the binary tree */
        else if(Map.get(w).height > h)
            Map.put(w,new pair(root.data,h));
        
        inorder(root.right,w+1,h+1,Map); 
    } 
      
    /* function should print the topView of 
     the binary tree */ 
    static void topView(Node root)
    { 
        if(root == null)
        return;
        
        /* map to store node at each vertical(horizontal) distance(Level)
        i.e. stores top view */
        TreeMap<Integer,pair> Map = new TreeMap<>();
      
        // obtain top view of binary tree into the Map
        inorder(root,0,0,Map); 
        
        /* traverse the map and print top view */
        for (Map.Entry<Integer, pair> i : Map.entrySet()) 
            System.out.print(i.getValue().nodeData+" ");
    } 
    
    /* main function to implement above function */
    public static void main (String[] args) 
    {
        /* construct the binary tree */
        Node root = new Node(1);  
        root.left = new Node(2);
        root.right = new Node(3);
        root.right.right = new Node(5);
        root.left.right = new Node(4);
        root.left.right.right = new Node(6);
        root.left.right.right.right = new Node(7);
        root.left.right.right.right.right = new Node(8);
        
        topView(root);
    }
}
