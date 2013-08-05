#pragma once

#include <gtest/gtest.h>
#include <czmq.h>

#include "MockProcessManagerCommand.h"
#include "ProcessManager.h"
#include "MockConf.h"
#include "CommandRequest.pb.h"

class NtpConfigCommandTest : public ::testing::Test {
public:

   NtpConfigCommandTest() {
      zctx_interrupted = false;
   }

protected:

   virtual void SetUp() {
      autoManagedManager = new MockProcessManagerCommand(conf);
      cmd.set_type(protoMsg::CommandRequest_CommandType_NTP_CONFIG);
   };

   virtual void TearDown() {
   }

   const MockConf conf;
   MockProcessManagerCommand* autoManagedManager;
   protoMsg::CommandRequest cmd;

};

