#pragma once

/// @file userver/storages/redis/mock_subscribe_client.hpp
/// @brief @copybrief storages::redis::MockSubscriptionTokenImpl

#include <userver/storages/redis/subscribe_client.hpp>
#include <userver/utest/utest.hpp>

#include <gmock/gmock.h>

USERVER_NAMESPACE_BEGIN

namespace storages::redis {

/// @brief Mocked storages::redis::SubscribeClient.
///
/// Mocking is done with google mock. Please
/// see GMock documentation on how to use this class. (Hint: GMock is
/// really powerful)
class MockSubscribeClient : public SubscribeClient {
public:
    ~MockSubscribeClient() override = default;
    MOCK_METHOD(
        SubscriptionToken,
        Subscribe,
        (std::string channel, SubscriptionToken::OnMessageCb on_message_cb, const CommandControl& command_control),
        (override)
    );
    MOCK_METHOD(
        SubscriptionToken,
        Ssubscribe,
        (std::string channel, SubscriptionToken::OnMessageCb on_message_cb, const CommandControl& command_control),
        (override)
    );
    MOCK_METHOD(
        SubscriptionToken,
        Psubscribe,
        (std::string pattern, SubscriptionToken::OnPmessageCb on_pmessage_cb, const CommandControl& command_control),
        (override)
    );
    MOCK_METHOD(size_t, ShardsCount, (), (const, override));
    MOCK_METHOD(bool, IsInClusterMode, (), (const, override));
};

/// @brief Mocked storages::redis::SubscriptionToken.
///
/// Although one can used it by itself,
/// it mostly for use with MockSubscribeClient. Here is a small example on
/// how to use this class
/// @snippet storages/redis/test/subscribe_client_mock_test.cpp SbTknExmpl1
class MockSubscriptionTokenImpl : public impl::SubscriptionTokenImplBase {
public:
    ~MockSubscriptionTokenImpl() override = default;

    MOCK_METHOD(void, SetMaxQueueLength, (size_t length), (override));

    MOCK_METHOD(void, Unsubscribe, (), (override));
};

}  // namespace storages::redis

USERVER_NAMESPACE_END
