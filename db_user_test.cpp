#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "db_user.h" 

class MockDBConnection : public IDBConnection {
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(bool, close, (), (override));
    MOCK_METHOD(bool, execQuery, (const std::string& query), (override));
};

// Тесты
TEST(ClassThatUsesDBTest, OpenConnectionSuccess) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, open()).WillOnce(testing::Return(true));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_TRUE(db_user.openConnection());
}

TEST(ClassThatUsesDBTest, OpenConnectionFail) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, open()).WillOnce(testing::Return(false));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_FALSE(db_user.openConnection());
}

TEST(ClassThatUsesDBTest, CloseConnectionSuccess) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, close()).WillOnce(testing::Return(true));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_TRUE(db_user.closeConnection());
}

TEST(ClassThatUsesDBTest, CloseConnectionFail) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, close()).WillOnce(testing::Return(false));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_FALSE(db_user.closeConnection());
}

TEST(ClassThatUsesDBTest, UseConnectionSuccess) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, execQuery(testing::_)).WillOnce(testing::Return(true));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_TRUE(db_user.useConnection("SELECT * FROM users;"));
}

TEST(ClassThatUsesDBTest, UseConnectionFail) {
    MockDBConnection mock_connection;
    EXPECT_CALL(mock_connection, execQuery(testing::_)).WillOnce(testing::Return(false));
    ClassThatUsesDB db_user(mock_connection);
    ASSERT_FALSE(db_user.useConnection("SELECT * FROM users;"));
}