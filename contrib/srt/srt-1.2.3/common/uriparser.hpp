/*
 * SRT - Secure, Reliable, Transport
 * Copyright (c) 2018 Haivision Systems Inc.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 * 
 */

#ifndef INC__URL_PARSER_H
#define INC__URL_PARSER_H

#include <string>
#include <map>
#include <cstdlib>


//++
// UriParser
//--

class UriParser
{
// Construction
public:

    enum DefaultExpect { EXPECT_FILE, EXPECT_HOST };

    UriParser(const std::string& strUrl, DefaultExpect exp = EXPECT_FILE);
    virtual ~UriParser(void);

    // Some predefined types
    enum Type
    {
        UNKNOWN, FILE, UDP, TCP, SRT, RTMP, HTTP
    };
    Type type();

// Operations
public:
    std::string uri() { return m_origUri; }
    std::string proto(void);
    std::string scheme() { return proto(); }
    std::string host(void);
    std::string port(void);
    unsigned short int portno();
    std::string hostport() { return host() + ":" + port(); }
    std::string path(void);
    std::string queryValue(const std::string& strKey);
    const std::map<std::string, std::string>& parameters() { return m_mapQuery; }

private:
    void Parse(const std::string& strUrl, DefaultExpect);

// Overridables
public:

// Overrides
public:

// Data
private:
    std::string m_origUri;
    std::string m_proto;
    std::string m_host;
    std::string m_port;
    std::string m_path;
    Type m_uriType;

    std::map<std::string, std::string> m_mapQuery;
};

//#define TEST1 1

#endif // _FMS_URL_PARSER_H_
