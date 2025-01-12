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

#pragma once

#include "watchman/thirdparty/jansson/jansson.h"

class w_string;

void cfg_shutdown();
void cfg_set_arg(const char* name, const json_ref& val);
void cfg_load_global_config_file();
w_string cfg_get_global_config_file_path();
json_ref cfg_get_json(const char* name);
const char* cfg_get_string(const char* name, const char* defval);
json_int_t cfg_get_int(const char* name, json_int_t defval);
bool cfg_get_bool(const char* name, bool defval);
double cfg_get_double(const char* name, double defval);
#ifndef _WIN32
mode_t cfg_get_perms(const char* name, bool write_bits, bool execute_bits);
#endif
const char* cfg_get_trouble_url();
json_ref cfg_compute_root_files(bool* enforcing);

// Convert root files to comma delimited string for error message
std::string cfg_pretty_print_root_files(const json_ref& root_files);

namespace watchman {

class Configuration {
 public:
  Configuration() = default;
  explicit Configuration(const json_ref& local);

  json_ref get(const char* name) const;
  const char* getString(const char* name, const char* defval) const;
  json_int_t getInt(const char* name, json_int_t defval) const;
  bool getBool(const char* name, bool defval) const;
  double getDouble(const char* name, double defval) const;

 private:
  json_ref local_;
};

} // namespace watchman
