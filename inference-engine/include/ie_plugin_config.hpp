// Copyright (C) 2018 Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief a header for advanced hardware related properties for IE plugins
 *        To use in SetConfig() method of plugins
 *        LoadNetwork() method overloads that accept config as parameter
 *
 * @file ie_plugin_config.hpp
 */
#pragma once

#include <string>

namespace InferenceEngine {

namespace PluginConfigParams {

/**
* @brief shortcut for defining configuration keys
*/
#define CONFIG_KEY(name) InferenceEngine::PluginConfigParams::_CONFIG_KEY(name)
#define _CONFIG_KEY(name) KEY_##name
#define DECLARE_CONFIG_KEY(name) static constexpr auto _CONFIG_KEY(name) = #name


/**
* @brief shortcut for defining configuration values
*/
#define CONFIG_VALUE(name) InferenceEngine::PluginConfigParams::name
#define DECLARE_CONFIG_VALUE(name) static constexpr auto name = #name

/**
* @brief generic boolean values
*/
DECLARE_CONFIG_VALUE(YES);
DECLARE_CONFIG_VALUE(NO);

/**
* @brief The name for setting CPU affinity per thread option.
* It is passed to IInferencePlugin::SetConfig(), this option should be used with values:
* PluginConfigParams::YES or PluginConfigParams::NO
*/
DECLARE_CONFIG_KEY(CPU_BIND_THREAD);

/**
* @brief The name for setting performance counters option.
* It is passed to IInferencePlugin::SetConfig(), this option should be used with values:
* PluginConfigParams::YES or PluginConfigParams::NO
*/
DECLARE_CONFIG_KEY(PERF_COUNT);

/**
* @brief The key defines dynamic limit of batch processing.
* Specified value is applied to all following Infer() calls. Inference Engine processes
* min(batch_limit, original_batch_size) first pictures from input blob. For example, if input
* blob has sizes 32x3x224x224 after applying plugin.SetConfig({KEY_DYN_BATCH_LIMIT, 10})
* Inference Engine primitives processes only beginner subblobs with size 10x3x224x224.
* This value can be changed before any Infer() call to specify a new batch limit.
*
* The paired parameter value should be convertible to integer number. Acceptable values:
* -1 - Do not limit batch processing
* >0 - Direct value of limit. Batch size to process is min(new batch_limit, original_batch)
*/
DECLARE_CONFIG_KEY(DYN_BATCH_LIMIT);

DECLARE_CONFIG_KEY(DYN_BATCH_ENABLED);

/**
* @brief The key controls threading inside Inference Engine.
* It is passed to IInferencePlugin::SetConfig(), this option should be used with values:
* PluginConfigParams::YES or PluginConfigParams::NO
*/
DECLARE_CONFIG_KEY(SINGLE_THREAD);

/**
* @brief This key directs the plugin to load a configuration file.
* The value should be a file name with the plugin specific configuration
*/
DECLARE_CONFIG_KEY(CONFIG_FILE);

/**
* @brief This key enables dumping of the kernels used by the plugin for custom layers.
* This option should be used with values: PluginConfigParams::YES or PluginConfigParams::NO (default)
*/
DECLARE_CONFIG_KEY(DUMP_KERNELS);

/**
* @brief This key controls performance tuning done or used by the plugin.
* This option should be used with values: PluginConfigParams::TUNING_CREATE,
* PluginConfigParams::TUNING_USE_EXISTING or PluginConfigParams::TUNING_DISABLED (default)
*/
DECLARE_CONFIG_KEY(TUNING_MODE);


DECLARE_CONFIG_VALUE(TUNING_CREATE);
DECLARE_CONFIG_VALUE(TUNING_USE_EXISTING);
DECLARE_CONFIG_VALUE(TUNING_DISABLED);

/**
* @brief This key defines the tuning data filename to be created/used
*/
DECLARE_CONFIG_KEY(TUNING_FILE);

/**
* @brief the key for setting desirable log level.
* This option should be used with values: PluginConfigParams::LOG_NONE (default),
* PluginConfigParams::LOG_WARNING, PluginConfigParams::LOG_INFO, PluginConfigParams::LOG_DEBUG
*/
DECLARE_CONFIG_KEY(LOG_LEVEL);

DECLARE_CONFIG_VALUE(LOG_NONE);
DECLARE_CONFIG_VALUE(LOG_WARNING);
DECLARE_CONFIG_VALUE(LOG_INFO);
DECLARE_CONFIG_VALUE(LOG_DEBUG);

/**
* @brief the key for setting of required device to execute on
* values: device id starts from "0" - first device, "1" - second device, etc
*/
DECLARE_CONFIG_KEY(DEVICE_ID);

/**
* @brief the key for enabling exclusive mode for async requests of different executable networks and the same plugin.
* Sometimes it's necessary to avoid oversubscription requests that are sharing the same device in parallel.
* E.g. There 2 task executors for CPU device: one - in FPGA, another - in MKLDNN. Parallel execution both of them leads to
* not optimal CPU usage. More efficient to run the corresponding tasks one by one via single executor.
*/
DECLARE_CONFIG_KEY(EXCLUSIVE_ASYNC_REQUESTS);

}  // namespace PluginConfigParams
}  // namespace InferenceEngine
