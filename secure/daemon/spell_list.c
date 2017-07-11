/*
 * Portia  2-5-99
 * A daemon that lists all spells along
 * with required skills and/or religions.
 *
 * Rewritten by Zaxan@Haven July 7, 2004
 * to change sorting by sphere then skill reqs.
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

void eventReport();
int SortSpells(string spell1, string spell2, mapping SphereSpells);
int SortSpellReqs(string skill1, string skill2, object spell);

/* 
 * The SortedSpells structure is constructed into
 * the following format:
 *
 * ([ "sphere" :
 *       ([ "spell" :
 *             ({
 *                  ({ "skill1", req }),
 *                  ({ "skill2", req })
 *             })
 *       ])
 * ]);
 *
 * The skill reqs are sorted as they are entered in
 * (first being the highest). Then the keys of the
 * spell mapping are sorted via their skill reqs or
 * alphabetically if they are equal. Then, each sphere
 * is printed out alphabetically with its list of
 * sorted spells.
 */

static void create()
{
    ::create();
    SetNoClean(1);
    eventReport();
}

void eventReport() {
    mapping SortedSpells = ([ ]);
    string *SortedSpellNames = ({ });
    string *Spheres = SPELLS_D->GetSpheres();
 
    unguarded( (: rm, DIR_PLAYER_HELP+"/allspells" :) );

    for(int i = 0; i < sizeof(Spheres); i++)
    {
	Spheres[i] = resolve_sphere(DIR_SPELLS+"/"+Spheres[i]+"/foo");
    }
    Spheres = sort_array(Spheres, 1);
    
    foreach(string Sphere in Spheres)
    {
	unguarded( (: write_file, DIR_PLAYER_HELP+"/allspells",
		      Sphere + "\n" :) );

	SortedSpells[Sphere] = ([ ]);
	
	foreach(string Spell in SPELLS_D->GetSphereSpells(Sphere))
	{
	    object SpellObject = SPELLS_D->GetSpell(Spell);

	    if (SpellObject && !undefinedp(SpellObject))
	    {
		string *Skills = SpellObject->GetSkills();

		/* Sort each spell's individual skill requirements */
		Skills = sort_array(Skills, (: SortSpellReqs :), SpellObject);

		SortedSpells[Sphere] += ([ Spell : allocate(sizeof(Skills)) ]);

		for(int i = 0; i < sizeof(Skills); i++)
		{
		    SortedSpells[Sphere][Spell][i] = ({ Skills[i], SpellObject->GetRequiredSkill(Skills[i]) });
		}
	    }
	}
	
	/* Now, sort spells with regards to eachother's requirements */
	SortedSpellNames = keys(SortedSpells[Sphere]);
	SortedSpellNames = sort_array(SortedSpellNames, (: SortSpells :), SortedSpells[Sphere]);

	/* Now that the spells are sorted, print them out */
	foreach(string Spell in SortedSpellNames)
	{
	    unguarded( (: write_file, DIR_PLAYER_HELP+"/allspells",
			"   "+Spell + ": " :) );

	    for(int i = 0; i < sizeof(SortedSpells[Sphere][Spell]); i++)
	    {
		mixed *Skill = SortedSpells[Sphere][Spell][i];
		
		unguarded( (: write_file, DIR_PLAYER_HELP+"/allspells",
			    Skill[0] + " : " + Skill[1] :) );

		if (i < sizeof(SortedSpells[Sphere][Spell])-1)
		{
		    unguarded( (: write_file, DIR_PLAYER_HELP+"/allspells", ", " :) );
		}
	    }

	    unguarded( (: write_file, DIR_PLAYER_HELP+"/allspells", "\n" :) );
	}
    }
}

/*
 * Sorts an individual spell's skill requirements so the highest
 * requirement ends up being first. If they are equal, it sorts
 * alphabetically.
 */
int SortSpellReqs(string skill1, string skill2, object spell)
{
    int skill1req = spell->GetRequiredSkill(skill1);
    int skill2req = spell->GetRequiredSkill(skill2);
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
 * Sorts two spells based on their skill requirements. If they
 * are equal, it sorts alphabetically.
 */
int SortSpells(string spell1, string spell2, mapping SphereSpells)
{
    int spell1_highestreq = SphereSpells[spell1][0][1];
    int spell2_highestreq = SphereSpells[spell2][0][1];
    int result = spell2_highestreq - spell1_highestreq;

    if (0 == result)
    {
	return strcmp(spell1, spell2);
    }
    else
    {
	return -result;
    }
}
