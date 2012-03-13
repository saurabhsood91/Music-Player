#ifndef MEDIAFILE_H
#define MEDIAFILE_H
#include<phonon/MediaObject>
#include<phonon/Path>
#include<phonon/AudioOutput>

class mediaobject:public Phonon::MediaObject{
    Phonon::Path path;
    Phonon::State newState;

public:
    mediaobject();
    Phonon::MediaObject *mobj;
    Phonon::AudioOutput *audioOutput;
    void playFile(QString);
    void playFiles(Phonon::MediaSource ms);
    void pauseFile();
    void stopFile();
};


#endif // MEDIAFILE_H
