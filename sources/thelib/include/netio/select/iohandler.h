/* 
*  Copyright (c) 2010,
*  Gavriloaie Eugen-Andrei (shiretu@gmail.com)
*  
*  This file is part of crtmpserver.
*  crtmpserver is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*  
*  crtmpserver is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with crtmpserver.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef NET_SELECT
#ifndef _IOHANDLER_H
#define	_IOHANDLER_H

#include "utils/core.h"

typedef enum _IOHandlerType {
    IOHT_ACCEPTOR,
    IOHT_TCP_CONNECTOR,
    IOHT_TCP_CARRIER,
    IOHT_UDP_CARRIER,
    IOHT_INBOUNDNAMEDPIPE_CARRIER,
    IOHT_TIMER,
    IOHT_STDIO
} IOHandlerType;

class DLLEXP IOHandler {
protected:
    static uint32_t _idGenerator;
    uint32_t _id;
protected:
    int32_t _inboundFd;
    int32_t _outboundFd;
private:
    IOHandlerType _type;
public:
    IOHandler(int32_t inboundFd, int32_t outboundFd, IOHandlerType type);
    virtual ~IOHandler();
    uint32_t GetId();
    int32_t GetInboundFd();
    int32_t GetOutboundFd();
    IOHandlerType GetType();
    virtual bool SignalOutputData() = 0;
    virtual bool OnEvent(select_event &event) = 0;
    static string IOHTToString(IOHandlerType type);
    virtual operator string() = 0;
};


#endif	/* _IOHANDLER_H */
#endif /* NET_SELECT */

