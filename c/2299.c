//
//  2299.c
//  CommonTool
//
//  Created by lizihong on 2023/1/19.
//  Copyright © 2023 AL. All rights reserved.
//

#include "2299.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool strongPasswordCheckerII(char * password){
    
    bool isContainSmall = false;
    bool isContainBig = false;
    bool isContainNum = false;
    bool isContainSpe = false;
    int length = 0;
    
    while (password[length] != '\0') {
        if (password[length] == password[length+1]) {
            return false;
        }
        if (password[length] >= '0' && password[length] <= '9') {
            isContainNum = true;
        } else if (password[length] >= 'a' && password[length] <= 'z') {
            isContainSmall = true;
        } else if (password[length] >= 'A' && password[length] <= 'Z') {
            isContainBig = true;
        } else if ((password[length] >= '!' && password[length] <= '-') || password[length] == '@' || password[length] == '^') {
            isContainSpe = true;
        }
        ++length;
    }
    
    return isContainSmall && isContainBig && isContainNum && isContainSpe && length>=8;
}
