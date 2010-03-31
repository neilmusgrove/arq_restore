/*
 Copyright (c) 2009, Stefan Reitshamer http://www.haystacksoftware.com
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 * Neither the names of PhotoMinds LLC or Haystack Software, nor the names of 
 their contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */ 

#import "DoubleIO.h"
#import "StringIO.h"
#import "SetNSError.h"


//FIXME: Delete this class? It's not used anywhere.


@implementation DoubleIO
+ (void)write:(double)d to:(NSMutableData *)data {
	NSString *str = [NSString stringWithFormat:@"%f", d];
	[StringIO write:str to:data];
}
+ (BOOL)read:(double *)value from:(id <BufferedInputStream>)is error:(NSError **)error {
    if (error) {
        *error = 0;
    }
    *value = 0;
	NSString *str;
    if (![StringIO read:&str from:is error:error]) {
        return NO;
    }
    if (!str) {
        SETNSERROR(@"DoubleIOErrorDomain", -1, @"nil string; expected a double");
        return NO;
    }
	BOOL ret = [[NSScanner scannerWithString:str] scanDouble:value];
    if (!ret) {
        SETNSERROR(@"DoubleIOErrorDomain", -1, @"%@ does not contain a double", str);
    }
    return ret;
}
@end
