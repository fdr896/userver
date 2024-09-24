"""
Plugin that imports the required fixtures to start the broker.
"""

import json
import logging


import pytest


pytest_plugins = [
    "testsuite.databases.kafka.pytest_plugin",
    "pytest_userver.plugins.core",
]


@pytest.fixture(scope="session")
def kafka_secdist(_kafka_service_settings, service_config) -> str:
    server_host = _kafka_service_settings.server_host
    server_port = _kafka_service_settings.server_port
    single_setting = {
        "brokers": f"{server_host}:{server_port}",
        "username": "",
        "password": "",
    }
    logging.info(f'Kafka brokers are: {single_setting["brokers"]}')

    secdist_config = {}
    secdist_config["kafka_settings"] = {}

    components = service_config["components_manager"]["components"]
    for component_name in components:
        is_kafka_producer = component_name.startswith("kafka-producer")
        is_kafka_consumer = component_name.startswith("kafka-conumer")
        if is_kafka_producer or is_kafka_consumer:
            secdist_config["kafka_settings"][component_name] = single_setting

    return json.dumps(secdist_config)
