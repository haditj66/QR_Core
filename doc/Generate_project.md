# ⚙️ `cgen QR_generate`

The `cgen QR_generate` command is used to **generate your AEROS project** based on its configuration file.

This command must always include:
```
cgen QR_generate <type> <target>
```

where:

| Argument | Description |
|-----------|--------------|
| `<type>` | The project type. Use **`c`** for CPP or **`r`** for RQT. |
| `<target>` | The name of the target you want to generate (for example, the specific EXE target defined in your config). |

---

### Example usage
```bash
cgen QR_generate c defaultTest
```
→ generates the **CPP** target `defaultTest`.

```bash
cgen QR_generate r defaultTestRos
```
→ generates the **RQT** target `defaultTestRos`.

This command must be run **inside the module’s root directory**, where the `config/<module>.cs` file exists.  
It reads that config file, finds the target definition, and generates all corresponding project files accordingly.

---

## ✅ Summary

| Command | Description |
|----------|--------------|
| `cgen QR_generate c <target>` | Generate CPP target from config. |
| `cgen QR_generate r <target>` | Generate RQT target from config. |

Always include both arguments — the type and the target — when running this command.
