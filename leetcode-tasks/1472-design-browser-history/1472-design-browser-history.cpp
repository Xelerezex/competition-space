#include <gtest/gtest.h>

class BrowserHistory
{

public:

    BrowserHistory(std::string homepage)
        : m_history{ homepage }
        , m_currentPosition{ std::begin(m_history) }
    {
    }
    
    void visit(std::string url)
    {
        m_currentPosition = m_history.insert(std::next(m_currentPosition), url);
        m_history.erase(
            std::next(m_currentPosition), 
            std::end(m_history)
        );
    }
    
    std::string back(int steps)
    {
        const auto position = static_cast<int>(
            std::distance(
                std::begin(m_history), 
                m_currentPosition
            )
        );
        if (position - steps <= 0)
        {
            m_currentPosition = std::begin(m_history);
            return *m_currentPosition;
        }

        std::advance(m_currentPosition, -steps);
        return *m_currentPosition;
    }
    
    std::string forward(int steps)
    {
        const auto position = static_cast<int>(
            std::distance(
                std::begin(m_history), 
                m_currentPosition
            )
        );

        if (position + steps >= m_history.size())
        {
            m_currentPosition = std::prev(std::end(m_history));
            return *m_currentPosition;
        }

        std::advance(m_currentPosition, steps);
        return *m_currentPosition;
    }

private:

    std::list<std::string> m_history;
    std::list<std::string>::iterator m_currentPosition;

};

TEST (SolutionTest, Example1)
{
    BrowserHistory browserHistory("leetcode.com");

    browserHistory.visit("google.com");   // "leetcode.com" -> "google.com"
    browserHistory.visit("facebook.com"); // "leetcode.com" -> "google.com" -> "facebook.com"
    browserHistory.visit("youtube.com");  // "leetcode.com" -> "google.com" -> "facebook.com" -> "youtube.com"

    EXPECT_EQ("facebook.com", browserHistory.back(1));
    EXPECT_EQ("google.com", browserHistory.back(1));
    EXPECT_EQ("facebook.com", browserHistory.forward(1));

    browserHistory.visit("linkedin.com"); // "leetcode.com" -> "google.com" -> "facebook.com" -> "linkedin.com"

    EXPECT_EQ("linkedin.com", browserHistory.forward(2));

    EXPECT_EQ("google.com", browserHistory.back(2));
    EXPECT_EQ("leetcode.com", browserHistory.back(7));
}

TEST (SolutionTest, Example2)
{
    BrowserHistory browserHistory("zav.com");

    browserHistory.visit("kni.com");   // "zav.com" -> "kni.com"

    EXPECT_EQ("zav.com", browserHistory.back(7));
    EXPECT_EQ("zav.com", browserHistory.back(7));
    EXPECT_EQ("kni.com", browserHistory.forward(5));
    EXPECT_EQ("kni.com", browserHistory.forward(1));

    browserHistory.visit("pwrrbnw.com"); // "zav.com" -> "kni.com" -> "pwrrbnw.com"
    browserHistory.visit("mosohif.com"); // "zav.com" -> "kni.com" -> "pwrrbnw.com" -> "mosohif.com"

    EXPECT_EQ("zav.com", browserHistory.back(9));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
