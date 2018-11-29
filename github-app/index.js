// index.js
// Main server code for GitHub App that listens to user's actions
// Maddie Zug & Simon Posada Fishman

module.exports = app => {
  app.log('Yay, the app was loaded!')

  app.on('installation', async context => {
    const account = context.payload.installation.account
    console.log(account)
    if (account.type == 'Organization') {
      const result = await context.github.orgs.createHook({
        org: account.login,
        name: 'web',
        config: {
          url: process.env.WEBHOOK_PROXY_URL,
          content_type: 'json',
          secret: process.env.WEBHOOK_SECRET,
          events: ['pull_request', 'push']
        }
      })
      console.log(result)
    }
  })

  app.on('push', async context => {
    console.log(context)
  })
}
