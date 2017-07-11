/*    /cmds/player/songs.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961028
 *    Version: @(#) songs.c 1.3@(#)
 *    Modified by Zedd@Haven on Jan17, 1999 to alphabetize the list of songs
 *    Sorted listing option added by Zaxan@Haven (25-Feb-2000)
 *    MOdified by Mahkefel@Haven on JanSom'n, 2011 to color
 */

#include <lib.h>
#include <daemons.h>
#include <music.h>

inherit LIB_DAEMON;
int GetMaxSongLevel(object, object);
int SortByLevel(string, string);
// bold here actually adds a lot to the command's output length, and
// that is bad. (command can runtime.)
string chealing = "%^BOLD%^GREEN%^";
string ccombat = "%^BOLD%^RED%^";
string cother = "%^BOLD%^CYAN%^";
string ctimed = "%^BOLD%^YELLOW%^";
string cdamage = "%^BOLD%^MAGENTA%^";

mixed cmd(string args) {
  object who;
  string *songs = ({ });
  mapping sorted = ([ ]);
  mapping colors = ([ ]);
  string tmp, song_list;
  int len, bSort, bColor = 0;

  if (angelp(this_player())) return "You don't have any songs, weirdo.";

  if (args) { // otherwise runtimes
  // handle flags
  if (member_array("-c",explode(args," ")) != -1) {
    bColor = 1;
    args = replace_string(args,"-c","");
  }
  if (member_array("-l",explode(args," ")) != -1) {
    bSort = 1;
    args = replace_string(args,"-l","");
  }
  args = replace_string(args," ","");
  }

  if( creatorp(this_player()) ) {
    if (!args) return "Show song book of whom?";
    who = find_living(args);
    if (!who || who->GetInvis() > rank(this_player()))
      return "Cannot find that person or incorrect argument.";
  }
  if(creatorp(who)) return "That person can't song.";
  if(!creatorp(this_player())) who = this_player();
  
  if (bColor) { 
    tmp = "You know the following " + sizeof(who->GetSongBook())+" ";
    tmp += chealing +"Healing%^RESET%^, "+ccombat+"Combat%^RESET%^, "+cother+"Other%^RESET%^,\n";
    tmp += ctimed+"Timed Shield%^RESET%^ and "+cdamage+"Damage Shield%^RESET%^ songs:\n";
    tmp += "song name (song level) : mastery percent %%/ maximum %%\n";
  } else {
    tmp = "You know the following " + sizeof(who->GetSongBook())+" songs:\n";
  }

  if (bSort) {
    songs = sort_array(keys(who->GetSongBook()), (: SortByLevel :) , 1);
  } else {
    songs = sort_array(keys(who->GetSongBook()),1);
  }
  foreach(string song in songs)       {
    object obj = SONGS_D->GetSong(song);
    string temp = base_name(obj);
    string sphere;
    string colorsong;

    if (undefinedp(obj)) continue;
    sphere = resolve_song_type(temp);

    // if we're doing colors, replace "song name" with "[pell nam]".
    // this is necessary for finding & recoloring unique song names.
    // (otherwise "poison sphere" will look funny due to grabbing "sphere's"
    // coloring
    if (bColor) {
      colorsong = sprintf("%:-20s","["+song[1..<2]+"]");
      if(obj->GetSongType() == SONG_HEALING) {
        colors[colorsong] =
          chealing + sprintf("%:-20s",song) + "%^RESET%^";
      } else if ( obj->GetSongType() == SONG_COMBAT ) {
        colors[colorsong] =
          ccombat + sprintf("%:-20s",song) + "%^RESET%^";
      } else if ( obj->GetSongType() == SONG_OTHER ) {
        colors[colorsong] =
          cother + sprintf("%:-20s",song) + "%^RESET%^";
      } else if ( obj->GetSongType() == SONG_DEFENSE ) {
        if ( obj->GetShieldType() == SHIELD_TIMED) {
          colors[colorsong] =
            ctimed + sprintf("%:-20s",song) + "%^RESET%^";
        } else {
          colors[colorsong] =
            cdamage + sprintf("%:-20s",song) + "%^RESET%^";
        }
      }
    } else {
        colorsong = song;
    }

    if(!sorted[sphere]) {
      sorted[sphere] = ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorsong,
        temp->GetSongLevel(),
        who->GetSongBook()[song], GetMaxSongLevel(who, load_object(temp))) });
    } else {
      sorted[sphere] += ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", colorsong,
        temp->GetSongLevel(),
        who->GetSongBook()[song], GetMaxSongLevel(who, load_object(temp))) });
    }
  }

  // Mahkefel 2011: i split the command into several eventPrints, cuz the 
  // command, even before mods, had a real threat of runtimes due to output
  // size on chars with crazy songs (like test characters)
  this_player()->eventPrint(tmp);
  if(!sizeof(keys(sorted)))       {
    tmp = "You know no songs.";
    this_player()->eventPrint(tmp);
  } else {
    foreach(string sph in keys(sorted)) {
      tmp = "In the "+sph+" sphere:\n";
      foreach(string spe in sorted[sph]) {
        int i = strlen(spe);
        if(i > len) {
          len = i;
        }
      }
      len = ((this_player()->GetScreen())[0]+2)/(len+2);
      tmp += format_page(sorted[sph], len);
      //tmp += "\n";
      if (bColor) {
        // this shit just got real
        foreach (string song in keys(colors)) {
          tmp = replace_string(tmp, song, colors[song]);
        }
      }
      this_player()->eventPrint(tmp);
    }
  } 
  return 1;
}

string GetHelp() {
    return ("Syntax: <songs>\n\n"
            "Lists all of your songs in your song book with your "
            "proficiency in each song. These arguments are available:\n\n"
            " -c display color highlights on songs.\n\n"
            " -l sort songs by song level.\n\n"
            "See also: skills, stats, status");
}

int GetMaxSongLevel(object who, object song) {
  int x = 100;
  int y;
  foreach(string skill in song->GetSkills()) {
     y = 5 * (who->GetSkillLevel(skill) - song->GetRequiredSkill(skill)) + 5;
     if (y < x) x = y;
  }
  return x;
}

int SortByLevel(string song1, string song2) {
  object oSong1 = SONGS_D->GetSong(song1);
  object oSong2 = SONGS_D->GetSong(song2);

  // handle renamed songs w/o crashing
  if (!oSong1) {
    return -1;
  } else if (!oSong2) {
    return 1;
  }

  if (oSong1->GetSongLevel() > oSong2->GetSongLevel()) {
    return 1;
  } else if (oSong1->GetSongLevel() < oSong2->GetSongLevel()) {
    return -1;
  } else {
    return 0;
  }
}
