#include <globalplatform/globalplatform.h>

#include <stdio.h>
#include <string.h>

static void set_tchar_field(TCHAR *dst, size_t dst_len, const TCHAR *src) {
    size_t n = _tcslen(src);
    if (n >= dst_len) {
        n = dst_len - 1;
    }
    _tcsncpy(dst, src, n);
    dst[n] = _T('\0');
}

int main(void) {
    OPGP_CARD_CONTEXT ctx;
    OPGP_CARD_INFO info;
    GP211_SECURITY_INFO sec;

    memset(&ctx, 0, sizeof(ctx));
    memset(&info, 0, sizeof(info));
    memset(&sec, 0, sizeof(sec));

    set_tchar_field(ctx.libraryName, sizeof(ctx.libraryName) / sizeof(TCHAR),
                    _T("gppcscconnectionplugin"));
    set_tchar_field(ctx.libraryVersion, sizeof(ctx.libraryVersion) / sizeof(TCHAR),
                    _T("1"));

    OPGP_ERROR_STATUS rc = OPGP_establish_context(&ctx);
    if (OPGP_ERROR_CHECK(rc)) {
        fprintf(stderr, "OPGP_establish_context failed: %s (%ld)\n",
                OPGP_stringify_error(rc.errorCode), (long)rc.errorCode);
        return 1;
    }

    OPGP_ERROR_STATUS rel = OPGP_release_context(&ctx);
    if (OPGP_ERROR_CHECK(rel)) {
        fprintf(stderr, "OPGP_release_context failed: %s (%ld)\n",
                OPGP_stringify_error(rel.errorCode), (long)rel.errorCode);
        return 1;
    }

    printf("GlobalPlatform context initialized and released successfully.\n");
    return 0;
}
