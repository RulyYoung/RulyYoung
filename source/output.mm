/*
 *  output.mm
 *  OGL002
 *
 *  Created by Ruly on 09-12-21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "output.h"
UILabel* g_lb;
void BindOutputLabel(UILabel* lb)
{
	g_lb = lb;
}

void output(const char* str)
{
	g_lb.text = [NSString stringWithFormat: @"%s", str ];
}
