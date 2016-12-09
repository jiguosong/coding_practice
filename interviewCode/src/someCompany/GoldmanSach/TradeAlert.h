/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef TRADE_ALERT_H
#define TRADE_ALERT_H

#include <stdio.h>
#include <string>

/**
 * The TradeAlert class is used to send an alert for a symbol when a risk limit is breached.
 */

class TradeAlert
{
public:
    /**
     * Constructor for sending trade alerts.
     *
     * @param symbol Symbol name to send an alert on.
     */

    TradeAlert( std::string const & symbol ) : m_symbol( symbol ) {}
    
    enum AlertType { EXCEEDED_QUANTITY_THRESHOLD, EXCEEDED_DELTA_THRESHOLD };
    
    /**
     * Method should be called when a threshold is breached ( accumulated quantity or delta >= threshold ).
     * Will notify external processes of excessive risk.
     * 
     * @param time Time of trade that caused the threshold to be breached.
     * @param alertType Quantity or Delta risk limit was breached
     * @param thresholdId symbol, sectorId or groupId of the breached threshold.
     */

    virtual void alert( unsigned int time, AlertType alertType, std::string const & thresholdId )
    {
        fprintf( stderr, "[%3u] TradeAlert Symbol: %-5s ThresholdId: %-10s Type: %s\n",
                time,
                m_symbol.c_str(),
                thresholdId.c_str(),
                alertType == EXCEEDED_QUANTITY_THRESHOLD ?  "EXCEEDED_QUANTITY_THRESHOLD" :
                alertType == EXCEEDED_DELTA_THRESHOLD    ?  "EXCEEDED_DELTA_THRESHOLD"    :
                                                            "UNKNOWN" );
    }

protected:
    /// @cond
    // IGNORE: this is part of the test harness.
    std::string m_symbol;
    /// @endcond
};

#endif
