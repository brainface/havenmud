#ifndef s_dirs_h
#define s_dirs_h

#define DIR_SECURE              "/secure"
#define DIR_SECURE_CFG	        DIR_SECURE "/cfg"
#define DIR_DATA                DIR_SECURE "/save"
#define DIR_SECURE_SAVE         DIR_SECURE "/save"
#define DIR_SECURE_DAEMONS      DIR_SECURE "/daemon"
#define DIR_ACCOUNTS            DIR_DAEMONS_SAVE "/accounts"
#define DIR_BOARDS              "/secure/save" "/boards"
#define DIR_CRES                 DIR_DATA "/immortals"
#define DIR_PLAYERS               DIR_DATA "/players"
#define DIR_LETTERS             DIR_DATA "/letters"
#define DIR_NEWSGROUPS         DIR_SECURE_SAVE "/newsgroups"
#define DIR_SECURE_OBJ         DIR_SECURE "/obj"
#define DIR_SOULS               "/souls"
#define DIR_POSTAL              DIR_DATA "/postal"
#define DIR_SUICIDE             DIR_DATA "/suicide"
#define DIR_RID                 DIR_DATA "/rid"
#define DIR_SECURE_DAEMONS_SAVE DIR_DATA "/daemons"
#define DIR_VOTES               DIR_DATA "/votes"
#define DIR_GOSSIP              DIR_DATA "/gossip"

#define DIR_INVASIONS       "/std/invasions"
#define DIR_TALENTS              "/std/talents"
#define DIR_SPELLS              "/std/spells"
#define DIR_SONGS               "/std/songs"

#define DIR_VERBS               "/verbs"
#define DIR_ADMIN_VERBS         DIR_VERBS "/admins"
#define DIR_COMMON_VERBS        DIR_VERBS "/common"
#define DIR_CREATOR_VERBS       DIR_VERBS "/creators"
#define DIR_ITEM_VERBS          DIR_VERBS "/items"
#define DIR_PLAYER_VERBS        DIR_VERBS "/players"
#define DIR_ROOM_VERBS          DIR_VERBS "/rooms"
#define DIR_SPELL_VERBS         DIR_VERBS "/spells"
#define DIR_UNDEAD_VERBS        DIR_VERBS "/undead"
#define DIR_VEHICLE_VERBS       DIR_VERBS "/vehicles"
#define DIR_CRAFTING_VERBS       DIR_VERBS "/crafting"
#define DIR_ACTION_VERBS        DIR_VERBS "/actions"

#define DIR_CFG                 "/cfg"

#define DIR_DAEMONS             "/daemon"
#define DIR_DAEMONS_DATA        DIR_DAEMONS "/db"
#define DIR_SOUL_FILES          DIR_DAEMONS "/soul"

#define DIR_LIB                 "/lib"

#define DIR_SECURE_LIB          DIR_SECURE "/lib"
#define DIR_SSTD                DIR_SECURE_LIB "/std"

#define DIR_LOGS                "/log"
#define DIR_DEBUG               DIR_LOGS "/debug"
#define DIR_ERROR_LOGS          DIR_LOGS "/errors"
#define DIR_PERSONAL_LOGS       DIR_LOGS "/personal"
#define DIR_REPORTS_LOGS        DIR_LOGS "/reports"
#define DIR_WATCH_LOGS          DIR_LOGS "/watch"

#define DIR_OBJ                 "/obj"

#define DIR_DOCS                "/doc"
#define DIR_FAQS                DIR_DOCS "/faq"
#define DIR_HELP                DIR_DOCS "/help"
#define DIR_CREATOR_HELP        DIR_HELP "/immortals"
#define DIR_CLASS_HELP          DIR_HELP "/classes"
#define DIR_LORE                DIR_HELP "/lore"
#define DIR_PLAYER_HELP         DIR_HELP "/players"
#define DIR_RACE_HELP           DIR_HELP "/races"
#define DIR_RELIGION_HELP       DIR_HELP "/religion"

#define DIR_CMDS                "/cmds"
#define DIR_SECURE_CMDS         "/secure/cmds"
#define DIR_ADMIN_CMDS          DIR_CMDS "/admins"
#define DIR_SECURE_ADMIN_CMDS   DIR_SECURE_CMDS "/admins"
#define DIR_COMMON_CMDS         DIR_CMDS "/common"
#define DIR_SECURE_COMMON_CMDS  DIR_SECURE_CMDS "/common"
#define DIR_CREATOR_CMDS        DIR_CMDS "/creators"
#define DIR_SECURE_CREATOR_CMDS DIR_SECURE_CMDS "/creators"
#define DIR_SAGE_CMDS           DIR_CMDS "/muses"
#define DIR_SECURE_SAGE_CMDS    DIR_SECURE_CMDS "/muses"
#define DIR_MUSE_CMDS           DIR_CMDS "/muses"
#define DIR_SECURE_MUSE_CMDS    DIR_SECURE_CMDS "/muses"
#define DIR_HM_CMDS             DIR_CMDS "/hm"
#define DIR_PLAYER_CMDS         DIR_CMDS "/players"
#define DIR_GUILD_CMDS          DIR_CMDS "/guild"
#define DIR_SECURE_PLAYER_CMDS  DIR_SECURE_CMDS "/players"

#define DIR_FTP                "/ftp"

#define DIR_STD               "/std/"

#define DIR_WWW                "/www"
#define DIR_WWW_DOCS           DIR_WWW "/doc"
#define DIR_WWW_EFUNS          DIR_WWW_DOCS "/efun"
#define DIR_WWW_SIMULEFUNS     DIR_WWW_DOCS "/sefun"
#define DIR_WWW_ERRORS         DIR_WWW "/errors"
#define DIR_WWW_GATEWAYS       DIR_WWW "/gateways"

#define DIR_UNDEAD_CMDS         DIR_CMDS "/undead"

#define REALMS_DIRS             "/realms"

#define DOMAINS_DIRS            "/domains"
#define WORLDS_DIRS             "/worlds"
#define DIR_STANDARD_DOMAIN     DOMAINS_DIRS "/staff"
#define DIR_UNDERWORLD_DOMAIN   DOMAINS_DIRS "/Underworld"

#define ESTATES_DIRS            "/estates"

#define DIR_NEWS                "/news"

#define DIR_SAVE                "/save"
#define DIR_KILLS               DIR_SAVE "/kills"

#define DIR_SHADOWS             "/shadows"

#define DIR_TMP                 "/tmp"

#endif /* s_dirs_h */
