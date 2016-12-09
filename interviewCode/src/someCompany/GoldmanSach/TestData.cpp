/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#include <string>

#include "ParamClient.h"
#include "TradeClient.h"
#include "TestData.h"
#include "ParamData.h"
#include "TradeData.h"

#define DO_PARAM_CALLBACKS( PARAM_TYPE, PARAM_ARRAY )                                            \
    for( unsigned int i=0; i<sizeof( PARAM_ARRAY ) / sizeof( PARAM_TYPE ); ++i )                \
        for( unsigned int j=0; j<Gs::Amm::ParamClient::s_paramClients.size(); ++j )                \
            Gs::Amm::ParamClient::s_paramClients[j]-> onParam( PARAM_ARRAY[i] );

#define DO_TRADE_CALLBACKS( TRADE_TYPE, TRADE_ARRAY )                                            \
    for( unsigned int i=0; i<sizeof( TRADE_ARRAY ) / sizeof( TRADE_TYPE ); ++i )                \
        if( Gs::Amm::TradeClient::s_tradeClients[ trades[i].symbol() ] )                        \
            Gs::Amm::TradeClient::s_tradeClients[ trades[i].symbol() ] -> onTrade( trades[i] );

void loadParamData1()
{
    Gs::Amm::GroupData groups[] = {
            Gs::Amm::GroupData( Gs::Amm::ParamData::INSERT, "Group1", 200, 20, 3000.0, 20 ),
            Gs::Amm::GroupData( Gs::Amm::ParamData::INSERT, "Group2", 200, 20, 3000.0, 20 ),
            Gs::Amm::GroupData( Gs::Amm::ParamData::INSERT, "Group3", 200, 20, 3000.0, 20 ) };
    DO_PARAM_CALLBACKS( Gs::Amm::GroupData, groups );
    
    Gs::Amm::SectorData sectors[] = {
            Gs::Amm::SectorData( Gs::Amm::ParamData::INSERT, "Financial" , 150, 10, 2500.0, 10 ),
            Gs::Amm::SectorData( Gs::Amm::ParamData::INSERT, "Healthcare", 150, 10, 2500.0, 10 ),
            Gs::Amm::SectorData( Gs::Amm::ParamData::INSERT, "Consumer"  , 150, 10, 2500.0, 10 ),
            Gs::Amm::SectorData( Gs::Amm::ParamData::INSERT, "Technology", 150, 10, 2500.0, 10 ) };
    DO_PARAM_CALLBACKS( Gs::Amm::SectorData, sectors );
    
    Gs::Amm::SymbolData symbols[] = {
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "BAC" , "Financial" , "Group1", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "WFC" , "Financial" , "Group2", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "PFE" , "Healthcare", "Group3", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "UNH" , "Healthcare", "Group1", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "JNJ" , "Consumer"  , "Group2", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "PG"  , "Consumer"  , "Group3", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "AAPL", "Technology", "Group1", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "INTC", "Technology", "Group2", 100, 10, 2000.0, 10 ) };
    DO_PARAM_CALLBACKS( Gs::Amm::SymbolData, symbols );
}

void loadParamData2()
{
    Gs::Amm::SymbolData symbols[] = {
            // moving BAC from group1 to group2
            Gs::Amm::SymbolData( Gs::Amm::ParamData::DELETE, "BAC" , "Financial" , "Group1", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "BAC" , "Financial" , "Group2", 100, 10, 2000.0, 10 ),
            // moving INTC from group2 to group1
            Gs::Amm::SymbolData( Gs::Amm::ParamData::DELETE, "INTC", "Technology", "Group2", 100, 10, 2000.0, 10 ),
            Gs::Amm::SymbolData( Gs::Amm::ParamData::INSERT, "INTC", "Technology", "Group1", 100, 10, 2000.0, 10 ) };
    DO_PARAM_CALLBACKS( Gs::Amm::SymbolData, symbols );
}

void loadTradeData1()
{
    Gs::Amm::TradeData trades[] = {
            // no alerts
            Gs::Amm::TradeData( "BAC" ,    0,    Gs::Amm::TradeData::BUY ,  25.0,  10 ),
            Gs::Amm::TradeData( "WFC" ,    1,    Gs::Amm::TradeData::SELL,  25.0,  10 ),
            Gs::Amm::TradeData( "PFE" ,    1,    Gs::Amm::TradeData::BUY ,  25.0,  10 ),
            Gs::Amm::TradeData( "UNH" ,    2,    Gs::Amm::TradeData::SELL,  25.0,  10 ),
            Gs::Amm::TradeData( "JNJ" ,    9,    Gs::Amm::TradeData::BUY ,  25.0,  10 ),
            Gs::Amm::TradeData( "PG"  ,   10,    Gs::Amm::TradeData::SELL,  25.0,  10 ),
            Gs::Amm::TradeData( "AAPL",   20,    Gs::Amm::TradeData::BUY ,  25.0,  10 ),
            Gs::Amm::TradeData( "INTC",   21,    Gs::Amm::TradeData::SELL,  25.0,  10 ),
            // alert AAPL (quantity)
            Gs::Amm::TradeData( "AAPL",   30,    Gs::Amm::TradeData::SELL,  15.0,  10 ),
            Gs::Amm::TradeData( "AAPL",   40,    Gs::Amm::TradeData::BUY ,  15.0,  90 ),
            Gs::Amm::TradeData( "AAPL",   41,    Gs::Amm::TradeData::SELL,  15.0,   9 ),
            Gs::Amm::TradeData( "AAPL",   41,    Gs::Amm::TradeData::SELL,  15.0,   2 ),
            // alert all Technology symbols ( quantity )
            Gs::Amm::TradeData( "INTC",  100,    Gs::Amm::TradeData::BUY ,  25.0,  30 ),
            Gs::Amm::TradeData( "AAPL",  102,    Gs::Amm::TradeData::BUY ,  25.0,  30 ),
            Gs::Amm::TradeData( "INTC",  104,    Gs::Amm::TradeData::SELL,  25.0,  30 ),
            Gs::Amm::TradeData( "INTC",  106,    Gs::Amm::TradeData::SELL,  25.0,  30 ),
            Gs::Amm::TradeData( "AAPL",  108,    Gs::Amm::TradeData::SELL,  25.0,  31 ),
            // alert all Group2 symbols ( quantity )
            Gs::Amm::TradeData( "WFC" ,  200,    Gs::Amm::TradeData::BUY ,  25.0,  50 ),
            Gs::Amm::TradeData( "JNJ" ,  204,    Gs::Amm::TradeData::BUY ,  25.0,  50 ),
            Gs::Amm::TradeData( "INTC",  208,    Gs::Amm::TradeData::SELL,  25.0,  50 ),
            Gs::Amm::TradeData( "JNJ" ,  216,    Gs::Amm::TradeData::SELL,  25.0,  51 ),
            // alert all Group1 symbols ( positive delta )
            Gs::Amm::TradeData( "BAC" ,  300,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "AAPL",  304,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "UNH" ,  308,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "BAC" ,  312,    Gs::Amm::TradeData::BUY ,  75.0,  11 ),
            // alert all Healthcare symbols ( negative delta )
            Gs::Amm::TradeData( "PFE" ,  400,    Gs::Amm::TradeData::SELL, 100.0,  10 ),
            Gs::Amm::TradeData( "UNH" ,  404,    Gs::Amm::TradeData::SELL, 100.0,  10 ),
            Gs::Amm::TradeData( "PFE" ,  408,    Gs::Amm::TradeData::SELL, 100.0,  10 ) };
    DO_TRADE_CALLBACKS( Gs::Amm::TradeData, trades );
}

void loadTradeData2()
{
    Gs::Amm::TradeData trades[] = {
            // alert all Group2 symbols ( quantity )
            Gs::Amm::TradeData( "WFC" ,  500,    Gs::Amm::TradeData::BUY ,  25.0,  50 ),
            Gs::Amm::TradeData( "JNJ" ,  504,    Gs::Amm::TradeData::BUY ,  25.0,  50 ),
            Gs::Amm::TradeData( "BAC" ,  508,    Gs::Amm::TradeData::SELL,  25.0,  50 ),
            Gs::Amm::TradeData( "JNJ" ,  516,    Gs::Amm::TradeData::SELL,  25.0,  51 ),
            // alert all Group1 symbols ( positive delta )
            Gs::Amm::TradeData( "INTC",  600,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "AAPL",  604,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "UNH" ,  608,    Gs::Amm::TradeData::BUY ,  75.0,  10 ),
            Gs::Amm::TradeData( "INTC",  612,    Gs::Amm::TradeData::BUY ,  75.0,  11 ) };
    DO_TRADE_CALLBACKS( Gs::Amm::TradeData, trades );
}
