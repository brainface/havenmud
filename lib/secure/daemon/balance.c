/* Spell info daemon
 * Duuk
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

static void create() {
	::create();
	SetNoClean(1);
}

void eventReport() {
	string *spheres = SPELLS_D->GetSpheres();
	string *spells;
	
	spheres = sort_array(spheres, 1);
	rm("/log/reports/spellbalance");
	foreach(string sphere in spheres) { 
		spells = SPELLS_D->GetSphereSpells(sphere);
		write_file("/log/reports/spellbalance", "\n" + sphere + "\n");
		foreach(string spellname in spells) {
			object spell = SPELLS_D->GetSpell(spellname);
			write_file("/log/reports/spellbalance", 
			  sprintf("%25s %25s %4d", spell->GetSpell(), 
			                           spell->GetSkills()[0] + ":" +
			                           spell->GetRequiredSkill(spell->GetSkills()[0]),
			                           spell->GetDifficulty()
			                           ) +"\n" );
		  }
		}
}

			                          