/**
 * @file AquariumView.h
 * @author Minsong Zheng
 *
 * View class for our aquarium
 */

#ifndef AQUARIUMAPP_CPP_AQUARIUMVIEW_H
#define AQUARIUMAPP_CPP_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow
{
private:
    /// An object that describes our aquarium
    Aquarium  mAquarium;
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;
    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);
    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishMagikarpFish(wxCommandEvent& event);
    void OnAddFishBuddhaFish(wxCommandEvent& event);
    void OnAddCastle(wxCommandEvent& event);
    void OnLeftDown(wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnFileSaveAs(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);
    void OnAnimate(wxTimerEvent& event);

public:
    void Initialize(wxFrame* parent);
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

};

#endif //AQUARIUMAPP_CPP_AQUARIUMVIEW_H
