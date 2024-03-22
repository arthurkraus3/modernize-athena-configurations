/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef ATHENAPOOLEXAMPLEALGORITHMS_WRITEDATA2_H
#define ATHENAPOOLEXAMPLEALGORITHMS_WRITEDATA2_H

/** @file AthenaPoolExampleAlgorithms/src/WriteData2.h
 *  @brief This file contains the class definition for the WriteData2 class.
 *  @author Peter van Gemmeren <gemmeren@anl.gov>
 *  $Id: WriteData2.h,v 1.1 2008-12-10 21:28:11 gemmeren Exp $
 **/

#include "AthenaBaseComps/AthReentrantAlgorithm.h"
#include "AthenaPoolExampleData/ExampleHitContainer.h"
#include "StoreGate/WriteHandleKey.h"

namespace AthPoolEx {

/** @class AthPoolEx::WriteData2
 *  @brief This class provides an example for writing event data objects to Pool.
 **/
class WriteData2 : public AthReentrantAlgorithm {
public: // Constructor and Destructor
   /// Standard Service Constructor
   WriteData2(const std::string& name, ISvcLocator* pSvcLocator);
   /// Destructor
   virtual ~WriteData2();

public:
/// Gaudi Service Interface method implementations:
   virtual StatusCode initialize() override;
   virtual StatusCode execute (const EventContext& ctx) const override;
   virtual StatusCode finalize() override;

   SG::WriteHandleKey<ExampleHitContainer> m_exampleHitKey { this, "ExampleHitKey", "MyHits" };
   SG::WriteHandleKey<ExampleHitContainer> m_aliasKey { this, "AliasKey", "PetersHits" };
};

} // end AthPoolEx namespace

#endif