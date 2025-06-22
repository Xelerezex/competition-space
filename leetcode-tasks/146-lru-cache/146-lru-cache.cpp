#include <gtest/gtest.h>

class LRUCache
{

public:

    LRUCache(int capacity)
        : m_capacity{ capacity }
    {
    }
    
    int get(int key)
    {
        const auto foundIter = m_hash.find(key);
        if (std::cend(m_hash) == foundIter)
        {
            return -1;
        }
        writeAsLRU(foundIter->second);

        return m_lastRecentlyUsedIter->value;
    }
    
    void put(int key, int value)
    {
        const auto foundIter = m_hash.find(key);
    
        // Update data
        if (std::cend(m_hash) != foundIter)
        {
            foundIter->second->value = value;
            writeAsLRU(foundIter->second);
            return;
        }

        // Or else insert 
        if (m_capacity > m_data.size())
        {
            pushValueToFront(key, value);
        }
        else
        {   
            // Remove Least Recently Used
            const auto keyToDelete = std::begin(m_data)->key;
            m_hash.erase(keyToDelete);
            m_data.pop_front();
            
            // Push to front
            pushValueToFront(key, value);
        }
    }

private:
    struct Node
    {
        int key{ -1 };
        int value{ -1 };
    };

    void pushValueToFront(int key, int value)
    {
        // push_front
        const auto dataIter = m_data.insert(
            std::end(m_data), 
            Node{ key, value }
        );
        m_hash.emplace(key, dataIter);
    }

    void writeAsLRU(const std::list<Node>::iterator& iter)
    {
        m_lastRecentlyUsedIter = iter;

        // Move LRU element to tail
        m_data.splice(
            std::end(m_data), 
            m_data, 
            m_lastRecentlyUsedIter
        );
    }

private:

    int m_capacity;

    std::list<Node> m_data;
    std::unordered_map<int, std::list<Node>::iterator> m_hash;
    std::list<Node>::const_iterator m_lastRecentlyUsedIter;

};

TEST (SolutionTest, CornerCase1)
{
    LRUCache cache(3);
    
    cache.put(1, 1); // {{1, 1}}
    cache.put(2, 2); // {{1, 1}, {2, 2}}
    cache.put(3, 3); // {{1, 1}, {2, 2}, {3, 3}}

    EXPECT_EQ(1, cache.get(1)); // {{2, 2}, {3, 3}, {1, 1}}
    EXPECT_EQ(2, cache.get(2)); // {{3, 3}, {1, 1}, {2, 2}}
    EXPECT_EQ(-1, cache.get(4));
    
    cache.put(4, 4); // { {1, 1}, {2, 2}, {4, 4}}

    EXPECT_EQ(1, cache.get(1)); // {{2, 2}, {4, 4}, {1, 1}}
    EXPECT_EQ(2, cache.get(2)); // {{4, 4}, {1, 1}, {2, 2}}
    EXPECT_EQ(-1, cache.get(3));
    EXPECT_EQ(4, cache.get(4)); // {{1, 1}, {2, 2}, {4, 4}}
    EXPECT_EQ(2, cache.get(2)); // {{1, 1}, {4, 4}, {2, 2}}

    cache.put(1, 8); // {{4, 4}, {2, 2}, {1, 8}}
    cache.put(3, 7); // {{2, 2}, {1, 8}, {3, 7}}

    EXPECT_EQ(8, cache.get(1)); // {{3, 7}, {2, 2}, {1, 8}}
    EXPECT_EQ(2, cache.get(2)); // {{3, 7}, {1, 8}, {2, 2}}
    EXPECT_EQ(7, cache.get(3)); // {{1, 8}, {2, 2}, {3, 7}}
    EXPECT_EQ(-1, cache.get(4));
    EXPECT_EQ(-1, cache.get(5));
    EXPECT_EQ(2, cache.get(2)); // {{1, 8}, {3, 7}, {2, 2}}
    EXPECT_EQ(7, cache.get(3)); // {{1, 8}, {2, 2}, {3, 7}}
    EXPECT_EQ(-1, cache.get(4));

    cache.put(1, 9); // {{2, 2}, {3, 7}, {1, 9}}
    cache.put(6, 6); // {{3, 7}, {1, 9}, {6, 6}}

    EXPECT_EQ(9, cache.get(1)); // {{3, 7}, {6, 6}, {1, 9}}
    EXPECT_EQ(-1, cache.get(2));
    EXPECT_EQ(7, cache.get(3)); // {{6, 6}, {1, 9}, {3, 7}}
    EXPECT_EQ(-1, cache.get(4));
    EXPECT_EQ(-1, cache.get(5));
    EXPECT_EQ(6, cache.get(6)); // {{1, 9}, {3, 7}, {6, 6},}
}

TEST (SolutionTest, Example1)
{
    LRUCache cache(2);
    
    cache.put(1, 10);

    EXPECT_EQ(10, cache.get(1));
    
    cache.put(2, 20);
    cache.put(3, 30);

    EXPECT_EQ(20, cache.get(2));
    EXPECT_EQ(-1, cache.get(1));
}

TEST (SolutionTest, Example2)
{
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);

    EXPECT_EQ(1, cache.get(1));
    
    cache.put(3, 3);

    EXPECT_EQ(-1, cache.get(2));

    cache.put(4, 4);

    EXPECT_EQ(-1, cache.get(1));
    EXPECT_EQ(3, cache.get(3));
    EXPECT_EQ(4, cache.get(4));

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
