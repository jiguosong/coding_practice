/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#include "TradeClient.h"

using namespace std;

namespace Gs { namespace Amm {

TradeClient::TradeClient( std::string const & symbol, TradeListener & listener )
        : m_listener( listener )
{
    // IGNORE: this is part of the test harness.
    s_tradeClients[ symbol ] = this;
}

// IGNORE: this is part of the test harness.
std::map< std::string, TradeClient * > TradeClient::s_tradeClients;

} // Amm
} // Gs
