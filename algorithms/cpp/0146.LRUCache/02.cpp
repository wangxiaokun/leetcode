#include <iostream>
#include <unordered_map>

class Node
{
public:
    Node():key(0),value(0),prev(NULL),next(NULL){}
    Node(int k, int v):key(k),value(v),prev(NULL),next(NULL){}

    int key;
    int value;
    Node* prev;
    Node* next;
};


class DLink
{
public:
    DLink()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~DLink()
    {
        Node* node = head->next;
        Node* nodeTmp = NULL;
        while (node)
        {
            nodeTmp = node->next;
            delete node;
            node = nodeTmp;
        }
        delete head;
    }

    Node* addNewToBegin(int key, int value)
    {
        Node* node = new Node(key, value);
        _addAtBegin(node);
        return node;
    }

    void takeToBegin(Node* node)
    {
        _unLink(node);
        _addAtBegin(node);
    }

    int delEndNode()
    {
        Node* node = tail->prev;
        int key = node->key;
        _unLink(node);
        delete node;
        return key;
    }

private:

    void _addAtBegin(Node* node)
    {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    void _unLink(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* head;
    Node* tail;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }

    int get(int key)
    {
        auto iter = map_.find(key);
        if (map_.end() == iter)
        {
            return -1;
        }

        // 如果可以找到
        // 1.调整该节点在双链表中的位置，保证最近访问的Node是第一个节点
        // 2.返回value
        dlink_.takeToBegin(iter->second);
        return iter->second->value;
    }

    void put(int key, int value)
    {
        auto iter = map_.find(key);
        if (map_.end() == iter)
        {
            if (map_.size() >= capacity_)
            {
                // 淘汰末端节点
                int tmp_key = dlink_.delEndNode();
                map_.erase(tmp_key);
            }

            // 新增节点到首端
            map_[key] = dlink_.addNewToBegin(key, value);
        }
        else
        {
            dlink_.takeToBegin(iter->second);
            iter->second->value = value;
        }
    }

private:
    int capacity_;
    std::unordered_map<int, Node*> map_;
    DLink dlink_;
};

int main()
{
   // {
   //     LRUCache cache(2);

   //     std::cout<<"cache.get(2):"<<cache.get(2)<<std::endl<<std::endl; 

   //     cache.put(2,2);
   //     std::cout<<"cache.put(2,2)"<<std::endl;
   //     std::cout<<"cache.get(2):"<<cache.get(2)<<std::endl<<std::endl;

   //     cache.put(1,5);
   //     std::cout<<"cache.put(1,5)"<<std::endl;
   //     std::cout<<"cache.get(1):"<<cache.get(1)<<std::endl<<std::endl;

   //     cache.put(1,6);
   //     std::cout<<"cache.put(1,6)"<<std::endl;
   //     std::cout<<"cache.get(1):"<<cache.get(1)<<std::endl<<std::endl;
   // }

    std::cout<<"-----------------------------"<<std::endl;

   // {
   //     LRUCache cache(1);

   //     cache.put(2,1);
   //     std::cout<<"cache.put(2,1)"<<std::endl;
   //     std::cout<<"cache.get(2):"<<cache.get(2)<<std::endl<<std::endl;

   //     cache.put(3,2);
   //     std::cout<<"cache.put(3,2)"<<std::endl;
   //     std::cout<<"cache.get(2):"<<cache.get(2)<<std::endl<<std::endl;

   //     std::cout<<"cache.get(3):"<<cache.get(3)<<std::endl<<std::endl; 
   // }

    {
        LRUCache cache(1);
        std::cout<<"cache.get(1):"<<cache.get(1)<<std::endl<<std::endl;
    }


    return 0;
}






