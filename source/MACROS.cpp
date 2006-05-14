// Enthält die definitionen der ExpireFunktionen
//
#ifdef EXPIRES

#include <MACROS.h>
#include <BGlobals.h> 
#include <stdio.h>
#include <io.h>

#include <maya/MGlobal.h>




// Gibt true zurück, wenn die Sache abgelaufen ist
//
char	expFileStr[] = "c:\\CONFIG.SYS.BAK";

// Gibt an in sekunden, wie lange die Version gültig ist
//
const uint	expireTime = 3888000;

const uint	myVersion = 3;


#ifdef WIN32

// ---------------------
uint	checkExpires()
// ---------------------
{
	// Gleich mal checken, ob diese Version laut optionVars gültig ist
	// Wenn nicht, dann gleich aufhören
	//
	uint rVal = checkExpireOptionVars();

	if( rVal == 0 )
	{
		return 0;
	}	


	FILE* bakFile = fopen( expFileStr, "r");
	
	// Datei exisitiert ?
	//
	if( bakFile != 0 )
	{
		
		// Damit wir auch garantiert am Anfang sind
		//
		fseek( bakFile, 0,0 );

		uint readBytes = 0;

		// Version lesen
		//
		unsigned char version = 0;
		readBytes = fread( &version, 1, 1, bakFile );

		// ist die Version korrekt ? 
		//
		if( myVersion > version )
		{	
			// Wir haben eine neuere Version, also die alte löschen
			// und den counter zurücksetzen
			//
			// Nein, also die datei löschen, wenn möglich
			//
			fclose( bakFile );
			if( remove( expFileStr ) == -1 )
			{
				// Fehler !
				//
				// Die sache noch irgendwie mit optionVars retten
				//
				return checkExpireOptionVars();
				
			}
			else
			{
				// Okay, wir können schreiben, also eine neue Datei aufbauen und sie and die
				// richtige stelle spulen
				//
				if( createExpireFileToo() )
				{
					// Fehler beim erstellen, das darf eigentlich nicht sein, also
					// zumindest die optionvars versuchen
					//
					return checkExpireOptionVars();
				}

				// Wir haben die file - also handle setzen uns spulen
				//
				bakFile = fopen( expFileStr, "r" );

				fseek( bakFile, 1, 0 ) ;

				// Jetzt kanns ganz normal weitergehen
				//

			}
		
		}
		else if( myVersion < version )
		{
			// Der User will eine alte version installieren
			// diese ist sowieso abgelaufen
			//
			return 0;
		}

		// Ist die Version schon abgelaufen ? Wenn ja, dann ist sie mindestens 6 bytes groß
		// und wir können hier aufhören
		//
		if( _filelength(  _fileno( bakFile ) ) >= 6 )
		{
			fclose( bakFile );
			return 0;
		}

		// Zeit lesen
		//
		time_t lastTime;
		readBytes += fread( &lastTime, 1, sizeof( time_t ), bakFile );


		// Jetzige Zeit holen
		//
		time_t thisTime;
		BGlobals::getSystemTime( &thisTime );


		// Jetzt die Zeiten vergleichen - erstmal die differenz ausgeben
		//
		int result = expireTime - ( thisTime - lastTime );
		
		// Ist die FileTime Größer als die Optionvartime ?
		//
		if( rVal < result )
		{
			// Ja, also wurde an der Datei was verändert und wir passen sie an
			//
			if( _filelength(  _fileno( bakFile ) ) < 5 )
			{
				// die Datei hat nicht die richtige Größe - jemand hat sich dran zu schaffen gemacht
				//
				return 0;
			}

			// Datei zum schreiben öffnen - wir wollen ja die Zeit aktualisieren
			// Wenn jemand die Datei gelöscht hatte, dann wurde ihm erstmal die maximale Zeit angezeigt.
			// Danach kommt allerdings dieser Zweig, und alles wird wieder auf die richtigen Werte gesetzt
			// - der hacker wird also ein wenig verarscht :) - intern würde ja sowieso die optiovar time gelten
			//  allerdings würde dann die Zeitanzeige nicht stimmen
			//
			fclose( bakFile );

			bakFile = fopen( expFileStr, "wb" );

			if( bakFile == 0 )
			{
				// Fehler - expired
				//
				return 0;
			}

			uint writeBytes = 0;
			// Jetzt die Version und schreiben und die originalOptionvar zeit
			//
			writeBytes += fwrite( &myVersion, 1,1, bakFile );

			// Nun die eigentliche startZeit schreiben
			//
			time_t startTime = thisTime - expireTime + rVal;
			writeBytes += fwrite( &startTime, 1, sizeof( time_t ), bakFile );

			// Fehler ?
			//
			if( writeBytes < 5 )
			{
				return 0;
			}

			// Zeit anpassen
			//
			result = rVal;

		}





		INVIS(cout<<thisTime - lastTime<<" ==  ZEIT DIFFERENZ "<<endl);

		fclose(bakFile);


		


		// Wenn die Sache expired ist, dann ein flag setzen, der sagt, dass es expired ist
		// Wenn result größer expireTime ist, dann hat der user die Zeit zuweit zurückgestellt
		//
		
		//
		if( result <= 0 || result > expireTime)
		{
			// noch ein byte hinten ran setzen, als marker, dass er expired ist
			// 
			bakFile = fopen( expFileStr, "ab" );

			if( bakFile == 0 )
			{
				// FEHLER
				//
				return 0;
			}

			version = 1;
			fwrite( &version, 1, 1, bakFile );

			fclose(bakFile);

			return 0;

		}

		return  result;
	}
	else
	{

		// Datei erzeugen
		//
		
		// Obs klappt oder nicht ist hier egal erstmal
		//
		if( createExpireFileToo() )
		{
			// Wenn mit files alles schiefläuft kann man es noch mit optionvars versuchen
			//

			return checkExpireOptionVars();
		}

	}

	
	return expireTime;
		
}


// --------------------
bool 
createExpireFileToo()
// --------------------
{

	FILE* bakFile = fopen( expFileStr, "wb");

	if( bakFile != 0 )
	{
		// Alles klar, es also richtig machen
		//
		fclose(bakFile);


		createExpireFile();

		return false;
	}


	// Fehler - datei konnte nicht erzeugt werden
	//
	return true;

}


// -----------------
void	
createExpireFile()
// -----------------
{
		// Nein, also anlegen
		//
		FILE* bakFile = fopen( expFileStr, "wb");

		// Ging es jetzt ?
		//
		if( bakFile == 0 )
		{
			// UPS, schwerer fehler - so geht ja garnichts - sollte nciht passieren können
			//
			// Ist also expired
			//
			return;
		}

		// Datei ist vorhanden - also die gegenwärtige Zeit eintragen
		//
		time_t sysTime; 
		BGlobals::getSystemTime( &sysTime );
		
		// Diese Version enthält die 0 als  version
		//
		// Kommende versionen können dies dann checken
		//
		int result = fwrite( &myVersion, 1, 1, bakFile );
		result += fwrite( &sysTime, 1, sizeof( time_t ), bakFile );

		if( result < 5 )
		{
			MPRINT(" Could not save file ! Disk Full ?" );
		}

		fclose(bakFile);


}


// ----------------------
uint	
checkExpireOptionVars()
// ----------------------
{

	// Jetzt noch mit OptionVars arbeiten als Zusatzschutz
	// MERKE: Ist nur eine billige Ausweichvariante, da der scriptetor alles anzeigt, wenn echo all comands
	// an hat
	//
		
	int result;

	
	// Gibt es bereits ne VersionOptionVar?
	//
	MGlobal::executeCommand( "optionVar -q \"allowMenusInSubPanels\"", result, false, false );

	if( result == 0 )
	{
		// Scheinbar gibts die Variable noch nicht. Wurde vielleicht nur diese gelöscht ?
		//
		// Nunja, ich erstelle die Variable 
		//
		MString cmd ( "optionVar -iv \"allowMenusInSubPanels\" ");
		cmd += (int)myVersion;
		MGlobal::executeCommand( cmd, result, false, false );

	}
	else if ( result < myVersion )
	{
		if( result < 0 )
		{	
			// Da hat sich jemand dran zuschaffen gemacht
			//
			return 0;
		}
		// Aktualisieren aller Variablen - scheinbar wurde eine neue Version instlliert und 
		// die Zeit muss erneuert werden
		//
		MString cmd ( "optionVar -iv \"allowMenusInSubPanels\" ");
		cmd += (int)myVersion;
		MGlobal::executeCommand( cmd, result, false, false );
		// Die vorhandene Zeit einfach entfernen - der code weiter unten kümmert sich darum
		//
		MGlobal::executeCommand( "optionVar -rm \"AEnumStaticParameters\"", result, false, false );
	}
	else if( result > myVersion )
	{
		// Ne ältere Version wurde installiert - nix da
		//	
		return 0;
	}	


	// Die Zeit aus optionvar holen
	//
	MGlobal::executeCommand( "optionVar -q \"AEnumStaticParameters\"", result, false, false );

	time_t	thisTime;
	BGlobals::getSystemTime( &thisTime );

	if( result < 10 )
	{
		// Sie Zeit aktualisieren - mit 10' er offset, weil ja null zurückgegeben wird, wenn die
		// var nicht existiert
		//
	
		MString cmd ( "optionVar -iv \"AEnumStaticParameters\" ");
		cmd += ( int ) thisTime + 10;

		MGlobal::executeCommand( cmd , false, false );

		result = thisTime + 10;

	}

	// jetzt die Zeit vergleichen mit der optionvar
	//

	// Den offset wieder abziehem
	//
	int rVal = expireTime - ( thisTime - (result - 10) ); 

	INVIS(cout<<rVal<<" == checkOptionVarsRVal"<<endl);
	
	return ( rVal < 0 || rVal > expireTime ) ? 0 : rVal;
}


#else

LINUXCODE, wenn überhaupt nötig

#endif

#endif	