/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef TRADE_CLIENT_H
#define TRADE_CLIENT_H

#include <string>
#include <map>

#include "TradeData.h"

namespace Gs { namespace Amm {

/**
 * The TradeListener class provides an interface for receiving TradeData updates via callbacks.
 */

class TradeListener
{
public:

    /**
     * Callback method that will be called automatically by TradeClient when a trade occurs.
     *
     * @param trade Reference to TradeData object with details of new trade.
     */

    virtual void onTrade( const TradeData & trade ) = 0;
};

/**
  * The TradeClient class creates a trade subscription for a given symbol. Trade update callbacks
  * are provided to the TradeListener object registered in the constructor.
  */

class TradeClient
{
public:

    /**
     * Constructor subscribes the listener to trades for the given symbol.
     *
     * @param symbol Symbol name to subsribe to.
     * @param listener TradeListener object to receive trade callbacks on.
     */

    TradeClient( std::string const & symbol, TradeListener & listener );

    /// @cond
    // IGNORE: this is part of the test harness.
    void onTrade( const TradeData & trade ) { m_listener.onTrade( trade ); }

private:

    // IGNORE: this is part of the test harness.
    TradeListener & m_listener;

public:

    // IGNORE: this is part of the test harness.
    static std::map< std::string, TradeClient * > s_tradeClients;
    /// @endcond
};


} // Amm
} // Gs

#endif
