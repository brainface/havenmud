//      /daemon/mudlib/economy_d.c
//      from the Dead Souls Mudlib
//      a daemon to handle currenciy inflation
//      created by Descartes of Borg 931114

#include <lib.h>
#include <privs.h>
#include <save.h>
#include <clock.h>

inherit LIB_DAEMON;

private mapping Currencies;
int LastInflation;

void create() {
    string *borg;
    float temps, tmp;
    int i;

    daemon::create();
    SetNoClean(1);
    Currencies = ([]);
    unguarded( (: restore_object, SAVE_ECONOMY :) );
}

void add_currency(string type, float rate, float infl, float wt) {
    if(!((int)master()->valid_apply(({ PRIV_CMDS })))) return;
    if(!mapp(Currencies)) Currencies = ([]);
    if(!type || !rate || Currencies[type]) return;
    Currencies[type] = ([ "rate":rate, ]);
    save_object(SAVE_ECONOMY);
}

void change_currency(string type, string key, float x) {
    if(!((int)master()->valid_apply( ({ PRIV_CMDS }) ))) return;
    if(!mapp(Currencies)) Currencies = ([]);
    if(!type || !Currencies[type] || !key || !x) return;
    if(!Currencies[type][key]) return;
    Currencies[type][key] = x;
    save_object(SAVE_ECONOMY);
}

float __Query(string type, string key) {
    if(!Currencies[type]) return 0.0;
    else return Currencies[type][key];
}

string *__QueryCurrencies() { return keys(Currencies); }

string *GetCurrencies() { return keys(Currencies); }
