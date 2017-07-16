 /*    /daemon/language.c
  *
  *    handles unique phonetic sounds for various languages
  *    Balishae@haven
  *    7/99
  */

#include <lib.h>
#include <save.h>
#include <privs.h>

#define DEFAULT ({ "wumm", "argle", "scruvy", "bing", "larf", "kronga",\
"siggera", "gyro", "hephis", "darmok", "tanagra",\
"carkan", "blurgle", "jing", "migra", "furn", "nitzelshnizzit", "folnar",\
"pampa", "bunrit", "eyne", "duh", "habbrish",\
})

inherit LIB_DAEMON;

private mapping Languages = ([]);


static void create() {
  daemon::create();
  SetNoClean(1);
    if( unguarded((: file_size(SAVE_LANGUAGES __SAVE_EXTENSION__) :)) > 0 )
    unguarded((: restore_object(SAVE_LANGUAGES) :));
    if(!Languages) Languages = ([]);
}

void AddLanguage(string file) {
    string array sounds;
    string array lines;
    string language;
    
    if( !file_exists(file) ) error("No such file: " + file);
    lines = explode(read_file(file),"\n");
    lines = filter(lines, function(string str) {
                          if( strlen(str) == 0 ) {
                  return 0;
                  }
                  if( str[0] == '#' ) {
                  return 0;
                  }
                  if( str[0] == ' ' || str[0] == '\t' ) {
                  return 0;
                  }
                  return 1;
                           });
    language = lines[0];
    if(Languages[language]) error("Language already defined");
    sounds = lines[1..];
    if(sizeof(sounds)  < 1) error("No sounds defined in language file");
    Languages[language] = sounds;
    save_object(SAVE_LANGUAGES);
}

void RemoveLanguage(string language) {
    map_delete(Languages,language);
    save_object(SAVE_LANGUAGES);
}

string array GetLanguages() {
    return keys(Languages);
}

string array GetLanguage(string language) {
    if(!Languages[language] || sizeof(Languages[language]) < 1)
      return DEFAULT;
    return Languages[language];
}

int GetLanguageExists(string language) {
  if (Languages[language]) return 1;
  return 0;
}
