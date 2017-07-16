/*    /daemon/songs.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961027
 *    Version: @(#) songs.c 1.2@(#)
 *    Last modified: 96/10/28
 */

#include <lib.h>
#include <dirs.h>
#include <std.h>
#include <music.h>
#include <daemons.h>

inherit LIB_DAEMON;

private mapping Songs = ([]);

void eventReloadSongs();

static void create() {
    daemon::create();
    SetNoClean(1);
    eventReloadSongs();
    SONG_LIST_D->eventReport();
}

void eventReloadSongs() {
    string *dirs = ({ });
    string *songs = ({ });

    Songs = ([]);
    dirs = get_dir(DIR_SONGS + "/");
    foreach(string dir in dirs) {
      songs = get_dir(DIR_SONGS + "/" + dir + "/*.c");
        foreach(string song in songs) {
      object ob = find_object(DIR_SONGS + "/" + dir + "/" + song);
	
	if( ob ) {
	    ob->eventDestruct();
	}
  if (ob = load_object(DIR_SONGS + "/" + dir + "/" + song) ) {
	    song = ob->GetSong();
	    if( song ) {
		Songs[song] = ob;
	    }
	}
    }
  }
}

object GetSong(string song) {
    if( !Songs[song] ) {
	eventReloadSongs();
    }
    return Songs[song];
}

string *GetSongs() {
   return (keys(Songs));
   }

