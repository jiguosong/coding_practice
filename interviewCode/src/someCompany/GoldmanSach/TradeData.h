/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef TRADE_DATA_H
#define TRADE_DATA_H

#include <string>

namespace Gs { namespace Amm {

struct TradeData
{
    public:
        enum Side { BUY, SELL };
        
        TradeData( const char * symbol, unsigned int time, Side side, double price, unsigned int quantity )
                : m_symbol   ( symbol   ),
                  m_time     ( time     ),
                  m_side     ( side     ),
                  m_price    ( price    ),
                  m_quantity ( quantity ) {}
        
        const std::string & symbol()   const { return m_symbol   ; }
        unsigned int        time()     const { return m_time     ; }
        Side                side()     const { return m_side     ; }
        double              price()    const { return m_price    ; }
        unsigned int        quantity() const { return m_quantity ; }
    
    private:
        std::string  m_symbol   ;
        unsigned int m_time     ;
        Side         m_side     ;
        double       m_price    ;
        unsigned int m_quantity ;
};

} // Amm
} // Gs

#endif
