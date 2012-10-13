#include "mediafile.h"
#include <iostream>

mediaobject::mediaobject()
{
    mobj = new Phonon::MediaObject(this);
    audioOutput =new Phonon::AudioOutput(Phonon::MusicCategory, this);
}

void mediaobject::playFile(QString filename)
{
    mobj->setCurrentSource(Phonon::MediaSource(filename));

    audioOutput =new Phonon::AudioOutput(Phonon::MusicCategory, this);
    path = Phonon::createPath(mobj, audioOutput);
    mobj->play();
}

void mediaobject::pauseFile()
{
    mobj->pause();
}

void mediaobject::stopFile()
{
    mobj->stop();
}

void mediaobject::playFiles(Phonon::MediaSource ms)
{
    mobj->setCurrentSource(ms);
    path = Phonon::createPath(mobj, audioOutput);
    mobj->play();
}
