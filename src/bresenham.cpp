/*
* libtcod
* Copyright (c) 2008-2018 Jice & Mingos & rmtew
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * The name of Jice or Mingos may not be used to endorse or promote
*       products derived from this software without specific prior written
*       permission.
*
* THIS SOFTWARE IS PROVIDED BY JICE, MINGOS AND RMTEW ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL JICE, MINGOS OR RMTEW BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <bresenham.hpp>

// ********** bresenham line drawing **********
void TCODLine::init(int xFrom, int yFrom, int xTo, int yTo) {
	TCOD_line_init(xFrom,yFrom,xTo,yTo);
}

bool TCODLine::step(int *xCur, int *yCur) {
	return TCOD_line_step(xCur,yCur) != 0;
}

static TCODLineListener *line_listener=NULL;

// C to C++ bridge
extern "C" bool internalListener(int x,int y) {
	return line_listener->putPoint(x,y) ? 1 : 0;
}

bool TCODLine::line(int xFrom, int yFrom, int xTo, int yTo, TCODLineListener *plistener) {
	line_listener=plistener;
	return TCOD_line(xFrom,yFrom,xTo,yTo,internalListener) != 0;
}
