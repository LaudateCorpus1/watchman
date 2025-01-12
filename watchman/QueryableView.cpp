/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "QueryableView.h"
#include "watchman/Errors.h"

namespace watchman {
QueryableView::~QueryableView() {}

/** Perform a time-based (since) query and emit results to the supplied
 * query context */
void QueryableView::timeGenerator(w_query*, QueryContext*) const {
  throw QueryExecError("timeGenerator not implemented");
}

/** Walks files that match the supplied set of paths */
void QueryableView::pathGenerator(w_query*, QueryContext*) const {
  throw QueryExecError("pathGenerator not implemented");
}

void QueryableView::globGenerator(w_query*, QueryContext*) const {
  throw QueryExecError("globGenerator not implemented");
}

void QueryableView::allFilesGenerator(w_query*, QueryContext*) const {
  throw QueryExecError("allFilesGenerator not implemented");
}

uint32_t QueryableView::getLastAgeOutTickValue() const {
  return 0;
}

std::chrono::system_clock::time_point QueryableView::getLastAgeOutTimeStamp()
    const {
  return std::chrono::system_clock::time_point{};
}

void QueryableView::ageOut(PerfSample&, std::chrono::seconds) {}

bool QueryableView::isVCSOperationInProgress() const {
  static const std::vector<w_string> lockFiles{".hg/wlock", ".git/index.lock"};
  return doAnyOfTheseFilesExist(lockFiles);
}
} // namespace watchman
