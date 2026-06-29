#!/usr/bin/env pwsh
# Push rifttrace to GitHub after authenticating once.
# Requires: GitHub CLI (gh) logged in as abdohware-hue

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$RepoRoot = Split-Path -Parent $PSScriptRoot
Set-Location $RepoRoot

if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Write-Error "Install GitHub CLI: https://cli.github.com/"
}

$auth = gh auth status 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "Run: gh auth login"
    Write-Host "Choose: GitHub.com -> HTTPS -> Login with browser"
    gh auth login
}

if (-not (git remote get-url origin 2>$null)) {
    gh repo create rifttrace `
        --private `
        --source . `
        --remote origin `
        --description "C++17 RIFT binary telemetry archive parser" `
        --push
} else {
    git push -u origin main
}

Write-Host "Done: https://github.com/abdohware-hue/rifttrace"
