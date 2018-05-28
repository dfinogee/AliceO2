// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

// Declaration of a transient MC label class for TOF

#ifndef ALICEO2_FIT_MCLABEL_H_
#define ALICEO2_FIT_MCLABEL_H_

#include "SimulationDataFormat/MCCompLabel.h"

namespace o2
{
namespace fit
{
class MCLabel : public o2::MCCompLabel
{
 private:
  Int_t mCFD = -1;

 public:
  MCLabel() = default;
  MCLabel(Int_t trackID, Int_t eventID, Int_t srcID, Int_t cfd)
    : o2::MCCompLabel(trackID, eventID, srcID), mCFD(cfd) {}
  Int_t getCFD() const { return mCFD; }
};
} // namespace fit
} // namespace o2

#endif
