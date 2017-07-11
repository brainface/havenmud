/*    /lib/npc.c
 *    from the Dead Souls LPC Library
 *    a npc basenpc
 *    created by Descartes of Borg 950331
 *    Version: @(#) npc.c 1.5@(#)
 *    Last modified: 96/12/15
 */

#include <lib.h>
#include <function.h>

inherit LIB_NPC;

static void create() {
	npc::create();
}

/* This entire file exists only for backwards compatability.
 * You may safely assume it does nothing.
 * Duuk
 */