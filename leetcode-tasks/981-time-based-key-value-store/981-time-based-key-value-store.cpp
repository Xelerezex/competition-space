#include <gtest/gtest.h>
#include <utility>

class TimeMap
{

public:

    TimeMap() = default;
    
    void set(std::string key, std::string value, int timestamp)
    {
        const auto& findKeyIter = m_storage.find(key);
        if (std::cend(m_storage) == findKeyIter)
        {
            m_storage.emplace(
                key,
                std::vector<std::pair<int, std::string>>{ 
                    std::make_pair(timestamp, value)
                }
            );
        }
        else
        {
            m_storage.at(key).emplace_back(timestamp, value);
        }
    }
    
    std::string get(std::string key, int timestamp)
    {   
        const auto& findKeyIter = m_storage.find(key);
        if (std::cend(m_storage) == findKeyIter)
        {
            return "";
        }
        const auto& [id, values] = *findKeyIter;

        auto index = lower_bound_in_storage(
            values,
            timestamp
        );

        // Corner case is timestamp lower than first
        if (values.empty() || ( timestamp < cbegin(values)->first ))
        {
            return "";
        }
        // Corner case if timestamp bigger
        if (index == values.size())
        {
            return values.at(index - 1).second;
        }

        // If timestamp in range - move to the left limit 
        const auto& currentTimestamp = values.at(index).first;
        if (timestamp != currentTimestamp)
        {
            index = index == 0 ? index : index - 1;
        }
        return values.at(index).second;
    }

private:

    std::size_t lower_bound_in_storage(
        const std::vector<std::pair<int, std::string>>& data,
        int target
    )
    {
        // regular stuff
        std::size_t leftIndex = 0;
        std::size_t rightIndex = data.size();

        // specialy lower_bound variables
        std::size_t currentIndex = 0; // like middle
        std::size_t count = data.size();
        std::size_t step = 0;

        while (count > 0)
        {
            currentIndex = leftIndex;
            step = count / 2;
            currentIndex += step;

            if (data.at(currentIndex).first < target)
            {
                leftIndex = ++currentIndex;
                count -= step + 1;
            }
            else 
            {
                count = step;
            }
        }

        return leftIndex;
    }

private:

    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> m_storage;

};

TEST (SolutionTest, CornerCase1)
{
    TimeMap timeMap;

    timeMap.set("test", "one", 10);
    timeMap.set("test", "two", 20);
    timeMap.set("test", "three", 30);
    
    auto expected = timeMap.get("test", 15);
    EXPECT_EQ(expected, "one");

    expected = timeMap.get("test", 25);
    EXPECT_EQ(expected, "two");
    
    expected = timeMap.get("test", 35);
    EXPECT_EQ(expected, "three");
}

TEST (SolutionTest, CornerCase2)
{
    TimeMap timeMap;

    timeMap.set("key1", "value1", 10);
    auto expected = timeMap.get("key1", 1);
    EXPECT_EQ(expected, "");
    
    expected = timeMap.get("key1", 10); 
    EXPECT_EQ(expected, "value1");
    
    expected = timeMap.get("key1", 11); 
    EXPECT_EQ(expected, "value1");
}

TEST (SolutionTest, Example1)
{
    TimeMap timeMap;

    timeMap.set("alice", "happy", 1);
    auto expected = timeMap.get("alice", 1);
    EXPECT_EQ(expected, "happy");
    
    expected = timeMap.get("alice", 2); 
    EXPECT_EQ(expected, "happy");
    
    timeMap.set("alice", "sad", 3);
    expected = timeMap.get("alice", 3); 
    EXPECT_EQ(expected, "sad");
}

TEST (SolutionTest, Example2)
{
    TimeMap timeMap;
    
    timeMap.set("foo", "bar", 1);
    auto expected = timeMap.get("foo", 1);
    EXPECT_EQ(expected, "bar");
    
    expected = timeMap.get("foo", 3); 
    EXPECT_EQ(expected, "bar");
    
    timeMap.set("foo", "bar2", 4);
    expected = timeMap.get("foo", 4); 
    EXPECT_EQ(expected, "bar2");

    expected = timeMap.get("foo", 5); 
    EXPECT_EQ(expected, "bar2");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
