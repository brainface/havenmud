/*
 * Portia  2-5-99
 * A daemon that lists all songs along
 * with required skills.
 *
 * Rewritten by Zaxan@Haven July 7, 2004
 * to change sorting by type then skill reqs.
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

void eventReport();
int SortSongs(string song1, string song2, mapping TypeSongs);
int SortSongReqs(string skill1, string skill2, object song);

/* 
 * The SortedSongs structure is constructed into
 * the following format:
 *
 * ([ "type" :
 *       ([ "song" :
 *             ({
 *                  ({ "skill1", req }),
 *                  ({ "skill2", req })
 *             })
 *       ])
 * ]);
 *
 * The skill reqs are sorted as they are entered in
 * (first being the highest). Then the keys of the
 * song mapping are sorted via their skill reqs or
 * alphabetically if they are equal. Then, each type
 * is printed out alphabetically with its list of
 * sorted songs.
 */

static void create()
{
    ::create();
    SetNoClean(1);
    eventReport();
}

void eventReport() {
    mapping SortedSongs = ([ ]);
    string *SortedSongNames = ({ });
    string *Types = ({ "instrumental", "harmonies", "vocal" });
 
    unguarded( (: rm, DIR_PLAYER_HELP+"/allsongs" :) );

    foreach(string Type in Types)
    {
	unguarded( (: write_file, DIR_PLAYER_HELP+"/allsongs",
		      Type + "\n" :) );

	SortedSongs[Type] = ([ ]);
	
	foreach(string Song in get_dir(DIR_SONGS+"/"+Type+"/"))
	{
	    string SongName = (string)(DIR_SONGS+"/"+Type+"/"+Song)->GetSong();
	    object SongObject = SONGS_D->GetSong(SongName);

	    if (SongObject && !undefinedp(SongObject))
	    {
		string *Skills = SongObject->GetSkills();

		/* Sort each song's individual skill requirements */
		Skills = sort_array(Skills, (: SortSongReqs :), SongObject);

		SortedSongs[Type] += ([ SongName : allocate(sizeof(Skills)) ]);

		for(int i = 0; i < sizeof(Skills); i++)
		{
		    SortedSongs[Type][SongName][i] = ({ Skills[i], SongObject->GetRequiredSkill(Skills[i]) });
		}
	    }
	}
	
	/* Now, sort songs with regards to eachother's requirements */
	SortedSongNames = keys(SortedSongs[Type]);
	SortedSongNames = sort_array(SortedSongNames, (: SortSongs :), SortedSongs[Type]);

	/* Now that the songs are sorted, print them out */
	foreach(string Song in SortedSongNames)
	{
	    unguarded( (: write_file, DIR_PLAYER_HELP+"/allsongs",
			"   "+Song + ": " :) );

	    for(int i = 0; i < sizeof(SortedSongs[Type][Song]); i++)
	    {
		mixed *Skill = SortedSongs[Type][Song][i];
		
		unguarded( (: write_file, DIR_PLAYER_HELP+"/allsongs",
			    Skill[0] + " : " + Skill[1] :) );

		if (i < sizeof(SortedSongs[Type][Song])-1)
		{
		    unguarded( (: write_file, DIR_PLAYER_HELP+"/allsongs", ", " :) );
		}
	    }

	    unguarded( (: write_file, DIR_PLAYER_HELP+"/allsongs", "\n" :) );
	}
    }
}

/*
 * Sorts an individual song's skill requirements so the highest
 * requirement ends up being first. If they are equal, it sorts
 * alphabetically.
 */
int SortSongReqs(string skill1, string skill2, object song)
{
    int skill1req = song->GetRequiredSkill(skill1);
    int skill2req = song->GetRequiredSkill(skill2);
    int result = skill2req - skill1req;

    if (0 == result)
    {
	return strcmp(skill1, skill2);
    }
    else
    {
	return result;
    }
}

/*
 * Sorts two songs based on their skill requirements. If they
 * are equal, it sorts alphabetically.
 */
int SortSongs(string song1, string song2, mapping TypeSongs)
{
    int song1_highestreq = TypeSongs[song1][0][1];
    int song2_highestreq = TypeSongs[song2][0][1];
    int result = song2_highestreq - song1_highestreq;

    if (0 == result)
    {
	return strcmp(song1, song2);
    }
    else
    {
	return -result;
    }
}

