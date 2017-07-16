/* Next Try */
#include <lib.h>
#include <config.h>
#include <dirs.h>
#include <daemons.h>
inherit LIB_DAEMON;
varargs void eventGenerateReport(mapping, mapping, mapping, mapping, mapping, mapping);
string Race; 
string Gender;
string Class;
string Town;
string Guild;
string *Religion;
int Level;
int TestChar;

static void create() {
  mapping Races, Towns, Religions;
  mapping Genders, Classes, Guilds;
  daemon::create();
  eventGenerateReport(Races, Towns, Religions, Classes, Guilds, Genders);
  }

varargs void eventGenerateReport(mapping Races, mapping Towns, 
         mapping Religions, mapping Classes, mapping Guilds, mapping Genders) {
  Races = ([]);
  Towns = ([]);
  Religions = ([]);
  Classes = ([]);
  Genders = ([]);
  Guilds = ([]);
  foreach(string file in get_dir("/log/p_stats/") ) {
    rm("/log/p_stats/" + file);
  }
  foreach(string letter in get_dir(DIR_PLAYERS + "/" ) ) {
    foreach(string person in get_dir(DIR_PLAYERS + "/" + letter + "/") ) {
      restore_object(DIR_PLAYERS + "/" + letter + "/" + person);
      if (Level < MAX_NEWBIE_LEVEL) continue;
      if (TestChar) continue;
    if (Guild) {
      if (!Guilds[Guild]) Guilds[Guild] = 1;
        else Guilds[Guild]++;
    }
    if (!Races[Race]) Races[Race] = 1;
      else Races[Race]++;
    if (!Towns[Town]) Towns[Town] = 1;
      else Towns[Town]++;
    if (!Religions[Religion[0]]) Religions[Religion[0]] = 1;
     else Religions[Religion[0]]++;
  foreach(string valid_class in CLASSES_D->GetBaseClasses(Class) ) {
    if (!Classes[valid_class]) Classes[valid_class] = 1;
      else Classes[valid_class]++;
      }
    if (!Genders[Gender]) Genders[Gender] = 1;
      else Genders[Gender]++;
      }
    }
  write_file("/log/p_stats/classes",
      "Class lists, Remember that multi-class characters "
      "are counted as BOTH classes. \n");
  foreach(string P_CLASS in keys(Classes) ) {
    write_file("/log/p_stats/classes",
       "Class \"" + P_CLASS + "\" : " + Classes[P_CLASS] + "\n");
    }
    foreach(string guild in keys(Guilds)) {
      write_file("/log/p_stats/guilds",
         guild + " : " + Guilds[guild] + "\n");
    }
    foreach(string gender in keys(Genders) ) {
    write_file("/log/p_stats/genders", 
      "Gender \"" + gender + "\" : " + Genders[gender] + "\n");
    }
    foreach(string town in keys(Towns)) {
      write_file("/log/p_stats/towns",
        town + " has " + Towns[town] + " citizens. \n");
      }
    foreach(string race in keys(Races) ) {
      write_file("/log/p_stats/races",
        race + " : " + Races[race] + "\n" );
    }
    foreach(string religion in keys(Religions) ) {
      write_file("/log/p_stats/religions",
        religion + " has " + Religions[religion] + " followers.\n");
    }
  }
