
#ifndef BPTREE_H
#define BPTREE_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

class BPTree {
private:
    static const int ORDER = 4; // B+ Tree order (minimum 3)
    
    struct Node {
        bool is_leaf;
        std::vector<std::string> keys;
        std::vector<std::vector<int>> values; // Multiple values for same key
        std::vector<int> children; // Page numbers for child nodes
        int next_leaf; // For leaf nodes, pointer to next leaf (for range queries)
        
        Node(bool leaf = false) : is_leaf(leaf), next_leaf(-1) {}
    };
    
    std::string filename;
    std::fstream file;
    int root_page;
    int free_page_list;
    
    // File operations
    int allocate_page();
    void free_page(int page_num);
    void write_node(int page_num, const Node& node);
    Node read_node(int page_num);
    void flush();
    
    // Tree operations
    void split_leaf(int page_num, Node& node, const std::string& key, int value);
    void split_internal(int page_num, Node& node, const std::string& key, int child);
    std::pair<int, int> insert_not_full(int page_num, const std::string& key, int value);
    void delete_entry(int page_num, const std::string& key, int value);
    std::vector<int> find(const std::string& key);
    
public:
    BPTree(const std::string& file_name);
    ~BPTree();
    
    void insert(const std::string& key, int value);
    void remove(const std::string& key, int value);
    std::vector<int> search(const std::string& key);
    void close();
};

#endif // BPTREE_H

