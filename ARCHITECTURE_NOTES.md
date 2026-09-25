# Architecture Notes

## Overview

DeviceMonitorPlatform follows a dependency-inverted architecture:

UI → Application → Domain
              ↑
        Infrastructure

## Domain

Contains business concepts such as:
- Reading
- TransportConfig
Domain does not depend on Qt, SQLite, Modbus, etc.

## Application

Contains use cases:
- MonitorDevice
- ReadSensor

## Infrastructure

Contains technical implementations:


## Data Access

SQLite repositories, mappers and transaction handling live
inside Infrastructure/DataAccess.

## Dependency Rules

Domain must not depend on Infrastructure.
Application must not depend on concrete database implementations.
Infrastructure implements interfaces defined by inner layers.