/*
 * Data module
 * Generic data storage object
 * Balishae@haven
 */

#include <lib.h>
#include <privs.h>
#include <save.h>

#define DATA_OB_SAVE "/save/data_modules/"
inherit LIB_DAEMON;


mapping		Data = ([ ]);
string 		ModuleName;


string GetModuleId();
string SetModuleId(string str);
mixed SetData(string data, mixed val);
mixed GetData(string data);
string *GetDataKeys();


static void create()
{
	daemon::create();
	SetNoClean(1);
}

int SetData(string data, mixed val)
{
	restore_object(DATA_OB_SAVE + GetModuleId());
	Data[data] = val;
	save_object(DATA_OB_SAVE + GetModuleId());
	return Data[data]; 
}

int GetData(string data) 
{
	restore_object(DATA_OB_SAVE + GetModuleId());	
	return Data[data];
}

string *GetDataKeys()
{
	restore_object(DATA_OB_SAVE + GetModuleId());
	return keys(Data);
}

string SetModuleId(string str)
{
	return (ModuleName = str);
}

string GetModuleId()
{
	return ModuleName;
}