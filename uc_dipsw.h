//
//  uc_dipsw.h
//
//
//  Created by Sean Slamka on 9/17/14.
//
//  Lab Partners: Sean Slamka, Aydin Balci

#ifndef ____uc_dipsw__
#define ____uc_dipsw__

//#include <iostream>
//#include "Token.h"

typedef enum {
 uc_dipsw_1 = 4, // Represents subswitch 1
 uc_dipsw_2 = 5, // Represents subswitch 2
 uc_dipsw_3 = 6, // Represents subswitch 3
 uc_dipsw_4 = 7 // Represents subswitch 4
} uc_dipsw_t;
typedef enum {
 uc_dipsw_state_off = 1, // Represents the Off state
 uc_dipsw_state_on = 0 // Represents the On state
} uc_dipsw_state_t;
