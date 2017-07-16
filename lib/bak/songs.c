/*    /cmds/player/songs.c
 *    From Nightmare LPMud
 *    created by Descartes of Borg 961028
 *    Version: @(#) songs.c 1.3@(#)
 *    Last modified: 96/10/28
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;
int GetMaxSongLevel(object, object);

mixed cmd(string args) {
    object who;
    string array songs = ({});
    string tmp;
    mapping sorted = ([]);
    int len;
  
    if( creatorp(this_player()) ) {
    if (!args) {
       return "Show song book of whom?";
      }
      who = find_living(args);
      if (!who) {
        return "Cannot find that person.";
        }
    }
    if(creatorp(who)) {
      return "That person can't sing.";
    }
    tmp = "You know the following songs:\n";
   if(!creatorp(this_player())) who = this_player();
   	
	 foreach(string spell in sort_array(keys(who->GetSongBook()), 1))	{
	    string temp = base_name(SONGS_D->GetSong(spell));
	    string sphere;
	    
	    if (undefinedp(SONGS_D->GetSong(spell))) continue;
	    sphere = resolve_song_type(temp);
	    if(!sorted[sphere]) {
		    sorted[sphere] = ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", spell, temp->GetSongLevel(), who->GetSongBook()[spell], GetMaxSongLevel(who, load_object(temp))) });
	      } else {
		    sorted[sphere] += ({ sprintf("%:-20s (%-3d): %:-3d/%-3d%%", spell, temp->GetSongLevel(), who->GetSongBook()[spell], GetMaxSongLevel(who, load_object(temp))) });
	    }
	 }

	if(!sizeof(keys(sorted))) {
        tmp += "You know no songs.";
    }
	foreach(string sph in keys(sorted))  {
		tmp += capitalize(sph) + ":\n";
		foreach(string spe in sorted[sph]) {
		  int i = strlen(spe);
		  if(i > len) {
			  len = i;
		    }
		  }
		len = (this_player()->GetScreen())[0]/(len+2);
		tmp += format_page(sorted[sph], len);
		tmp += "\n";
	  }
    this_player()->eventPrint(tmp);
    return 1;
}

string GetHelp() {
    return ("Syntax: <songs>\n\n"
            "Lists all of your songs in your song book with your "
            "proficiency in each song.\n\n"
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