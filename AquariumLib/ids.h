/**
 * @file ids.h
 * @author Minsong Zheng
 *
 * ID values for our program.
 */

#ifndef AQUARIUM_IDS_H
#define AQUARIUM_IDS_H
/**
 * Fish id
 */
enum IDs {
    IDM_ADDFISHBETA = wxID_HIGHEST + 1,
    IDM_ADDFISHMAGIKARP = IDM_ADDFISHBETA + 1,
    IDM_ADDFISHBUDDHA = IDM_ADDFISHMAGIKARP + 1,
    IDM_ADDCASTLE = IDM_ADDFISHBUDDHA + 1
};

#endif //AQUARIUM_IDS_H