/* 
 * File:   signals.h
 * Author: tristram
 *
 * Created on 24 février 2009, 22:48
 */
#include "boost/signals.hpp"
#ifndef _SIGNALS_H
#define	_SIGNALS_H
extern boost::signal<void (int)> backtrack;
extern boost::signal<void ()> solver_start;
extern boost::signal<void ()> solver_stop;

#endif	/* _SIGNALS_H */

