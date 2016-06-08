// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLImmediateViewer.cc,v 1.3 1999/12/15 14:54:07 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// Andrew Walkden  7th February 1997
// Class G4OpenGLImmediateViewer : Encapsulates the `immediateness' of
//                               an OpenGL view, for inheritance by
//                               derived (X, Xm...) classes.

#ifdef G4VIS_BUILD_OPENGL_DRIVER

#include "G4OpenGLImmediateViewer.hh"

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include "G4ios.hh"
#include <assert.h>
#include <unistd.h>

G4OpenGLImmediateViewer::G4OpenGLImmediateViewer (G4OpenGLImmediateSceneHandler& scene):
G4VViewer (scene, -1),
G4OpenGLViewer (scene),
fSceneHandler (scene)
{}

#endif