/**
 * @file MainFrame.cpp
 * @author Minsong Zheng
 */

#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Aquarium", wxDefaultPosition,  wxSize( 1040,870 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto aquariumView = new AquariumView();
    aquariumView->Initialize(this);

    // Add it to the sizer
    sizer->Add(aquariumView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );
    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto fishMenu = new wxMenu();
    auto decorMenu = new wxMenu();
    auto saveMenu = new wxMenu();

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnHelp, this, wxID_ABOUT);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(fishMenu, L"&Add Fish");
    menuBar->Append(helpMenu, L"&Help");
    menuBar->Append(decorMenu, L"&Add Decor");
    menuBar->Append(saveMenu, L"Save &As...");
    saveMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");
    fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
    fishMenu->Append(IDM_ADDFISHMAGIKARP, L"&Magikarp Fish", L"Add a Magikarp Fish");
    fishMenu->Append(IDM_ADDFISHBUDDHA, L"&Buddha Fish", L"Add a Buddha Fish");
    decorMenu->Append(IDM_ADDCASTLE, L"&Castle", L"Add a Castle");

    SetMenuBar( menuBar );

    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Help menu option handlers
 * @param event
 */
void MainFrame::OnHelp(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Aquarium!",
            L"About Aquarium",
            wxOK,
            this);
}