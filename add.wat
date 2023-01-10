(module
  (type (;0;) (func (param i32 i32) (result i32)))
  (type (;1;) (func))
  (type (;2;) (func (param i32 i32 i32) (result i32)))
  (func (;0;) (type 1)
    nop)
  (func (;1;) (type 0) (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.add)
  (func (;2;) (type 2) (param i32 i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.const 1
    i32.const 2
    i32.const 3
    local.get 2
    i32.const 2
    i32.eq
    select
    local.get 2
    i32.const 3
    i32.eq
    select
    call_indirect (type 0))
  (func (;3;) (type 0) (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.mul)
  (func (;4;) (type 0) (param i32 i32) (result i32)
    local.get 0
    local.get 1
    i32.sub)
  (table (;0;) 5 5 funcref)
  (memory (;0;) 256 256)
  (export "memory" (memory 0))
  (export "add" (func 1))
  (export "temp" (func 2))
  (export "_initialize" (func 0))
  (elem (;0;) (i32.const 1) func 3 4 1 0)
  (data (;0;) (i32.const 1040) "\b0\04P"))
